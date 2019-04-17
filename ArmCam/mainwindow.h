/*
 *
 * 主窗体，包含按键控制，视频显示界面。
 *
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTimer"
#include "QImage"
#include "opencv2/opencv.hpp"
#include "imgprocess.h"
#include "log.h"
#include "QDateTime"

using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void ReadFrame();                   //读取视频帧
    void openCam_clicked();             //开启摄像头
    void closeCam_clicked();            //关闭摄像头
    void takeVideo_clicked();           //开始录像
    void stopVideo_clicked();           //停止录像
    void writeLog();                    //创建并写日志

private:
    Ui::MainWindow *ui;
    QTimer *timer;                      //帧计时
    QTimer *timerLog;                   //日志计时
    ImgProcess process;                 //图像处理对象
    Log log;                            //日志对象
    bool takeVideoFlag = false;         //视频录制标签
};

#endif // MAINWINDOW_H
