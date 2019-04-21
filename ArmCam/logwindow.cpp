#include "logwindow.h"
#include "ui_logwindow.h"
#include "myfile.h"
#include "string"

using namespace std;

LogWindow::LogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogWindow)
{
    ui->setupUi(this);
    setWindowTitle("ArmCamLog");
}

LogWindow::~LogWindow()
{
    delete ui;
}

void LogWindow::refreshLog()
{
    string message = this->mf.listLOG();
    QString qmessage = QString::fromStdString(message);
    ui->label->setText(qmessage);
}
