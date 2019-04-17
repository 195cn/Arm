/*
 * opencv视频处理对象
 */
#ifndef IMGPROCESS_H
#define IMGPROCESS_H

#include "opencv2/opencv.hpp"

using namespace cv;

class ImgProcess
{
private:
    Mat frame;
    VideoCapture cap;
    VideoWriter vw;
    String cascadeFile = "../haarcascade_frontalface_alt.xml";
    CascadeClassifier cascade;
    int fps = 30;
public:
    ImgProcess();
    void openCam();                      //开启摄像头
    bool isCamOpened();                  //判断摄像头是否开启
    int getFps();                        //获取Fps
    void closeCam();                     //释放摄像头
    void startVm(String video_name);     //新建录像文件
    void writeVideo();                   //录像
    void stopWrite();                    //停止录像
    Mat getFrame();                      //获取一帧


    //图像算法
    Mat toCanny(Mat src);
    Mat toBlur(Mat src);
    void loadCascade();                 //读取特征文件
    int toFaceDetect(double scale);     //运行人脸识别算法并绘图
};

#endif // IMGPROCESS_H
