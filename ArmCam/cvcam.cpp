/*测试类：opencv摄像头
 *
 *  test code
 *
 */
#include "cvcam.h"

CvCam::CvCam()
{

}

void CvCam::show()
{
    VideoCapture cap(0);
    namedWindow("CamShow");
    while(1)
    {
        Mat frame;
        Mat edges;

        cap >> frame;
        cvtColor(frame,edges,CV_BGR2GRAY);
        blur(edges,edges,Size(7,7));
        Canny(edges,edges,0,40,3);

        imshow("CamShow",edges);
        if(waitKey(30) == 27)
            break;
    }
    cap.release();
    destroyWindow("CamShow");

    cout << "end cam" << endl;
}
