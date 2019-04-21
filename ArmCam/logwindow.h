#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QDialog>
#include "myfile.h"

namespace Ui {
class LogWindow;
}

class LogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LogWindow(QWidget *parent = 0);
    ~LogWindow();
    void refreshLog();

private:
    Ui::LogWindow *ui;
    MyFile mf;
};

#endif // LOGWINDOW_H
