#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDateTime"
/*
 *
 * 主窗体，包含按键控制，视频显示界面。
 *
 */
#include "imgprocess.h"
#include "log.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("ArmCam");
    timer=new QTimer(this);
    timerLog = new QTimer(this);
    //信号槽
    connect(timer,SIGNAL(timeout()),this,SLOT(ReadFrame()),Qt::UniqueConnection);
    connect(ui->openCam, SIGNAL(clicked()), this, SLOT(openCam_clicked()),Qt::UniqueConnection);  //打开摄像头
    connect(ui->closeCam, SIGNAL(clicked()), this, SLOT(closeCam_clicked()),Qt::UniqueConnection);  //关闭摄像头
    connect(ui->takeVideo, SIGNAL(clicked()), this, SLOT(takeVideo_clicked()),Qt::UniqueConnection);    //开始录像
    connect(ui->stopVideo, SIGNAL(clicked()), this, SLOT(stopVideo_clicked()),Qt::UniqueConnection);    //停止录像
    connect(timerLog,SIGNAL(timeout()),this,SLOT(writeLog()),Qt::UniqueConnection);                              //写日志
}

MainWindow::~MainWindow()
{
    delete ui;
}
//视频帧读取：包含读帧，opencv转qt图像，填充适配label，显示，录像
void MainWindow::ReadFrame()
{
    Mat frame = process.getFrame();
    int faces_num = process.toFaceDetect(5.0);
    log.count(faces_num);
    //Format_Indexed8适用于单通道图像，如处理过后的灰度图
    //QImage image = QImage((const uchar*)temp.data,temp.cols,temp.rows,QImage::Format_Indexed8).rgbSwapped();

    //将抓取到的帧,转换为QImage格式,QImage::Format_RGB888使用24位RGB格式（8-8-8）存储图像
    QImage image = QImage((const uchar*)frame.data,frame.cols,frame.rows,QImage::Format_RGB888).rgbSwapped();
    QPixmap pixmap = QPixmap::fromImage(image);

    int width = ui->label->width();
    int height = ui->label->height();
    QPixmap fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    //QPixmap fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放

    //将图片显示到label上
    ui->label->setPixmap(fitpixmap);
    //    ui->label->setPixmap(pixmap);
    if(takeVideoFlag)
    {
        process.writeVideo();
    }
}


//开启摄像头按钮：开启摄像头，读取人脸识别种子，创建log文件，设定计时器
void MainWindow::openCam_clicked()
{
    if(process.isCamOpened())
    {
        cout << "ERROR : Cam is already open!" << endl;
    }
    else
    {
        process.openCam();
        process.loadCascade();

        //每次打开摄像头创建一个log文件
        QDateTime log_file_create_time =QDateTime::currentDateTime();
        QString log_file_create_string =log_file_create_time.toString("yyyy.MM.dd-hh:mm:ss");
        String log_name = "../log/log" + log_file_create_string.toStdString() + ".txt";
        log.createFile(log_name);
        cout << "日志文件创建完毕。" << endl;

        timer->start(process.getFps()); //开启定时器，FPS = 40
        timerLog->start(75*process.getFps());//开启日志定时器，75倍周期采样 = 3s
    }
}
//关闭摄像头按钮
void MainWindow::closeCam_clicked()
{
    timer->stop();//关闭定时器
    timerLog->stop();
    process.closeCam();//释放视频
    ui->label->setText("摄像头已关闭。");
    MainWindow::stopVideo_clicked();//stop take video.
}
//录像按钮
void MainWindow::takeVideo_clicked()
{
    cout << "Prepare save video." << endl;
    if(process.isCamOpened())
    {
        takeVideoFlag = true;
        //获取时间，生成录像文件名称
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy.MM.dd-hh:mm:ss");
        String video_name = "../dv/" + current_date.toStdString() + ".avi";
        process.startVm(video_name);
    }
    else
    {
        ui->label->setText("请打开摄像头，再录像。");
    }

}
//停止录像按钮
void MainWindow::stopVideo_clicked()
{
    takeVideoFlag = false;
    process.stopWrite();
}
//生成并写日志
void MainWindow::writeLog()
{
    if(process.isCamOpened())
    {
        //计算平均人数，如果检测到人脸则记录数据
        if(log.averageNum() > 0)
        {
            cout << "创建一条日志" << endl;
            QDateTime log_create_time =QDateTime::currentDateTime();
            QString create_time_string =log_create_time.toString("yyyy.MM.dd-hh:mm:ss");
            String log_time = create_time_string.toStdString();
            cout << "日志写入,计数容器清空:" << log.getNumSize() << endl;
            log.createLog(log_time);
            log.writeFile();
            cout << "写入完毕" << endl;
        }
        //清空计数容器
        log.cleanNum();
    }
}
