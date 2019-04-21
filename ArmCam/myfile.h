/*
 * 文件夹控制：遍历文件夹，删除最早录像，读取日志后十条
 *
 *
 */

#ifndef MYFILE_H
#define MYFILE_H

#include <stdio.h>
#include <dirent.h>
#include <string>

class MyFile
{
private:
    DIR* dir;
    struct dirent *dirp;
public:
    MyFile();
    void deleteDV();
    std::string listLOG();
};

#endif // MYFILE_H
