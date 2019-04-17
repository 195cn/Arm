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
    void openCam_clicked();          //开启摄像头
    void closeCam_clicked();         //关闭摄像头
    void takeVideo_clicked();     //开始录像
    void stopVideo_clicked();     //停止录像
    void writeLog();                    //写日志

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timerLog;
    ImgProcess process;
    Log log;
    bool takeVideoFlag = false;
};

#endif // MAINWINDOW_H
