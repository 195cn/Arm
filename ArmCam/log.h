#ifndef LOG_H
#define LOG_H

#include "vector"
#include "string"
#include "fstream"

using namespace std;

class Log
{
private:
    string log_message;     //日志最终信息
    vector<int> num;        //人数容器
    int data = 0;               //人数
    ofstream file;          //日志文件
public:
    Log();
    void count(int num);            //计数
    void cleanNum();        //清空容器
    int getNumSize();       //获取容器数量s
    int averageNum();       //人数均值计算
    void createLog(string log_time);        //生成日志条目
    void createFile(string log_name);       //创建日志文件
    void writeFile();       //写文件
    void closeFile();       //关闭文件
};

#endif // LOG_H
