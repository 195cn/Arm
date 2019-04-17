#include "log.h"
#include "iostream"
#include "cmath"

using namespace std;

/*
 *
 * 日志对象。
 *
 */

Log::Log()
{

}


void Log::count(int num)
{
    this->num.push_back(num);
}

void Log::cleanNum()
{
    this->num.clear();
}

int Log::getNumSize()
{
    return (int) this->num.size();
}

int Log::averageNum()
{
    vector<int> result = this->num;
    int num_size = (int) result.size();
    for(auto i:result)
        cout << i <<' ';
    cout << endl;
    double average = 0.0;
    if(num_size < 10)
    {
        cout << "Can't get useful message , cout less than 10." << endl;
    }
    else
    {
        vector<int>::iterator it;
        vector<int>::iterator it_temp;
        //冒泡排序
        for(it = result.begin();it != result.end()-1;it++)
        {
            for(it_temp = it + 1;it_temp != result.end();it_temp++)
            {
                if(*it > *it_temp)
                {
                     swap(*it,*it_temp);
                }
            }
        }

        for(auto i:result)
            cout << i <<' ';

        //取中间数的平均值
        for(it = result.begin() + 3;it != result.end() - 3;it++)
        {
            average+=(double) *it;
        }

        average = average /(num_size - 6);
        //四舍五入去平均值
    }

    this->data =  (int) round(average);
    cout << "average:" << this->data << endl;

    return this->data;
}

void Log::createLog(string log_time)
{
    this->log_message = "LOG:" + log_time + " NUM: " + to_string(this->data);
}

void Log::createFile(string log_name)
{
    this->file.open(log_name);
    cout << "Log:\"" << log_name << "\"create succeed" << endl;
}

void Log::writeFile()
{
    this->file << this->log_message << endl;
}

void Log::closeFile()
{
    this->file.close();
}
