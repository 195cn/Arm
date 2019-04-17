/*
 * opencv视频对象
 */
#include "imgprocess.h"

using namespace cv;
using namespace std;

ImgProcess::ImgProcess()
{

}

void ImgProcess::openCam()
{
    this->cap.open(0);
    cout << "Cam is open." << endl;
}

bool ImgProcess::isCamOpened()
{
    return this->cap.isOpened();
    cout << "Cam is opening, able to take video." << endl;
}

int ImgProcess::getFps()
{
    return this->fps;
}

void ImgProcess::closeCam()
{
    this->cap.release();
    cout << "Cam is closed." << endl;
}

cv::Mat ImgProcess::getFrame()
{
    this->cap >> this->frame;
    return this->frame;
}

void ImgProcess::startVm(String video_name)
{
    cv::Size sWH = cv::Size((int)this->cap.get(CV_CAP_PROP_FRAME_WIDTH),(int)this->cap.get(CV_CAP_PROP_FRAME_HEIGHT));
    vw.open(video_name,CV_FOURCC('M','J','P','G'),this->fps,sWH);
    cout << "Start take video:" << video_name << endl;
}

void ImgProcess::writeVideo()
{
    this->vw.write(this->frame);
}

void ImgProcess::stopWrite()
{
    this->vw.release();
    cout << "Save video..." << endl;
}

cv::Mat ImgProcess::toCanny(Mat src)
{
    Mat temp;
    cvtColor(src,temp,CV_BGR2GRAY);
    blur(temp,temp,Size(7,7));
    Canny(temp,temp,0,30,3);


    return temp;
}

cv::Mat ImgProcess::toBlur(Mat src)
{
    Mat temp;
    blur(src,temp,Size(7,7));
    return temp;
}
//读取种子文件
void ImgProcess::loadCascade()
{
    this->cascade.load(this->cascadeFile);
    cout << "Loading :\"" << this->cascadeFile << "\" succeed" << endl;
}

//人脸识别处理代码，源于opencv例子
int ImgProcess::toFaceDetect(double scale)
{
    Mat &img = this->frame;
    //double t = 0;
    vector<Rect> faces;
    const static Scalar color(255,0,0);
    Mat gray, smallImg;

    cvtColor( img, gray, COLOR_BGR2GRAY );
    double fx = 1 / scale;
    resize( gray, smallImg, Size(), fx, fx, INTER_LINEAR_EXACT );
    equalizeHist( smallImg, smallImg );

    //t = (double)getTickCount();
    cascade.detectMultiScale( smallImg, faces,
                              1.1, 2, 0
                              //|CASCADE_FIND_BIGGEST_OBJECT
                              //|CASCADE_DO_ROUGH_SEARCH
                              |CASCADE_SCALE_IMAGE,
                              Size(30, 30) );
    //t = (double)getTickCount() - t;
    //printf( "detection time = %g ms\n", t*1000/getTickFrequency());
    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Rect r = faces[i];
        Point center;
        int radius;

        double aspect_ratio = (double)r.width/r.height;
        if( 0.75 < aspect_ratio && aspect_ratio < 1.3 )
        {
            center.x = cvRound((r.x + r.width*0.5)*scale);
            center.y = cvRound((r.y + r.height*0.5)*scale);
            radius = cvRound((r.width + r.height)*0.25*scale);
            circle( img, center, radius, color, 3, 8, 0 );
        }
        else
            rectangle( img, Point(cvRound(r.x*scale), cvRound(r.y*scale)),
                       Point(cvRound((r.x + r.width-1)*scale), cvRound((r.y + r.height-1)*scale)),
                       color, 3, 8, 0);
    }
    this->frame = img;
    return (int) faces.size();
}
