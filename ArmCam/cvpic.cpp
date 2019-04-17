/*测试类：opencv图像处理
 *
 *  test code
 *
 */
#include "cvpic.h"

CvPic::CvPic()
{

}

void CvPic::getFileName(String file_name)
{
    this->file_name = file_name;
     cout << "Get filename succeed." << endl;
}

void CvPic::showFileName()
{
    cout << "Picture filename is:" << this->file_name <<endl;
}

void CvPic::readPic()
{
    this->src = imread(this->file_name);
    cout << "Read picture succeed." << endl;
}

void CvPic::showPic()
{
    cout << "Start show pic." << endl;
    imshow("ShowPic",this->src);
    waitKey(0);
}
