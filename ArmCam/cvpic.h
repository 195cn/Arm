/*测试类：opencv图像处理
 *
 *
 *
 */

#ifndef CVPIC_H
#define CVPIC_H
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class CvPic
{
private:
    Mat src;
    String file_name;
public:
    void getFileName(String file_name);
    void showFileName();
    void readPic();
    void showPic();
    CvPic();
};

#endif // CVPIC_H
