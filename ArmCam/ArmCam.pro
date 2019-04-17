#-------------------------------------------------
#
# Project created by QtCreator 2019-04-07T15:00:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ArmCam
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    cvpic.cpp \
    cvcam.cpp \
    imgprocess.cpp \
    log.cpp

HEADERS  += mainwindow.h \
    cvpic.h \
    cvcam.h \
    imgprocess.h \
    log.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/opencv3.4.5/include \
                /usr/local/opencv3.4.5/include/opencv \
                /usr/local/opencv3.4.5/include/opencv2

LIBS += \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_calib3d.so    \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_core.so   \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_dnn.so    \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_features2d.so \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_flann.so  \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_highgui.so    \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_imgcodecs.so  \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_imgproc.so    \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_ml.so \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_objdetect.so  \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_photo.so  \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_shape.so  \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_stitching.so  \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_superres.so   \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_videoio.so    \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_video.so  \
/usr/local/opencv3.4.5/lib/x86_64-linux-gnu/libopencv_videostab.so  \

