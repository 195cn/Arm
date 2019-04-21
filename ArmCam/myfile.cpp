/*
 * 文件夹控制：遍历文件夹，删除最早录像，读取日志后十条
 *
 *
 */
#include "myfile.h"
#include <vector>
#include <string>
#include <iostream>
#include "cstring"
#include "fstream"
#include "algorithm"

using namespace std;

MyFile::MyFile()
{

}

void MyFile::deleteDV()
{
    this->dir = opendir("../dv/");
    vector<string> dv_file;
    //遍历dv文件夹
    while((dirp = readdir(this->dir)) != nullptr)
    {
        if(dirp->d_type == DT_REG)
        {
            if(strcmp(dirp->d_name,"Readme.txt") != 0)
                dv_file.push_back(dirp->d_name);
        }
    }
    //按字典排序
    vector<string>::iterator it;
    vector<string>::iterator it_temp;
    //冒泡排序
    for(it = dv_file.begin();it != dv_file.end()-1;++it)
    {
        for(it_temp = it + 1;it_temp != dv_file.end();++it_temp)
        {
            if(*it > *it_temp)
            {
                swap(*it,*it_temp);
            }
        }
    }
    //    for(auto i:dv_file)
    //        cout << i <<endl;
    //删除最早的文件，在字典排序中数字最小也就是日期最小的排前面，所以删除第一个就好
    string first_file_fullname = "../dv/" + dv_file.front();
    remove(first_file_fullname.c_str());
    cout << "Remove " << first_file_fullname << endl;
    //关闭文件夹
    closedir(dir);
}

string MyFile::listLOG()
{
    this->dir = opendir("../log/");
    vector<string> log_file;
    //遍历log文件夹
    while((dirp = readdir(this->dir)) != nullptr)
    {
        if(dirp->d_type == DT_REG)
        {
            if(strcmp(dirp->d_name,"Readme.txt") != 0)
                log_file.push_back(dirp->d_name);
        }
    }
    //按字典排序
    vector<string>::iterator it;
    vector<string>::iterator it_temp;
    //冒泡排序
    for(it = log_file.begin();it != log_file.end()-1;++it)
    {
        for(it_temp = it + 1;it_temp != log_file.end();++it_temp)
        {
            if(*it > *it_temp)
            {
                swap(*it,*it_temp);
            }
        }
    }
    //    for(auto i:dv_file)
    //        cout << i <<endl;
    //读取最新的文件
    string first_file_fullname = "../log/" + log_file.back();
    cout << "Read log:" << log_file.back() <<endl;
    //准备一个容器，倒叙取出文件后10条。
    vector<string> log;
    vector<string>::iterator log_it;
    string log_message = "";
    ifstream infile;
    infile.open(first_file_fullname,ios::in|ios::binary);   //将文件流对象与文件连接起来
    if(infile.is_open())                  //若失败,则输出错误消息,并终止程序运行
    {
        string s;
        while(getline(infile,s))
        {
            log.push_back(s);
            //log_message += s + "\n";
        }
        //反序容器
        reverse(log.begin(),log.end());
        int i = 0;
        for(log_it = log.begin();log_it != log.end() && i<10;++log_it,++i)
        {
            log_message += *log_it + "\n";
            cout << *log_it << endl;
        }
        //log_message = "Nothing11";
    }
    else
    {
        log_message = "Nothing";
    }
    infile.close();             //关闭文件输入流


    //关闭文件夹
    closedir(dir);
    return log_message;
}
