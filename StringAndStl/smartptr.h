/**
 * @File: smartptr
 * @Author: Jialiangjun
 * @Description: 智能指针
 * @Date: Created on 14:57 2021-11-04.
 * @Modify:
 */
#ifndef STRINGANDSTL_SMARTPTR_H
#define STRINGANDSTL_SMARTPTR_H

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Report {
private:
    string str;
public:
    explicit Report(const string s):str(s){cout<<s<<" contructor!"<<endl;};
    ~Report(){cout<<str<<" destroy "<<endl;}
    void comment(){cout<<"This is "<<str<<endl;}
};


#endif //STRINGANDSTL_SMARTPTR_H
