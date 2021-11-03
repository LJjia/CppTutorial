/**
 * @File: Students
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 16:50 2021-10-22.
 * @Modify:
 */
#ifndef CODEREUSE_STUDENTS_H
#define CODEREUSE_STUDENTS_H

#include <iostream>
#include <valarray>
#include <string>

using namespace std;



class Students {
public:
    explicit Students(const string &n="Nobody"){
        name=n;
    }
    void run(int a){cout<<"run 1"<<endl;}
    void run(int a,int b){cout<<"run 2"<<endl;}
public:
    string name;
};


class Kids:private Students{
private:
public:
    const string& Name();
    using Students::run;
};







#endif //CODEREUSE_STUDENTS_H
