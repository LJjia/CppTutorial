/**
 * @File: error_class
 * @Author: Jialiangjun
 * @Description:  错误处理类
 * @Date: Created on 09:33 2021-11-02.
 * @Modify:
 */
#ifndef FRIENDSEXCEPTION_ERROR_CLASS_H
#define FRIENDSEXCEPTION_ERROR_CLASS_H

#include <iostream>
#include <string>
#include <exception>

using std::cout;
using std::endl;

class BadMessage1{
protected:
    int err;
public:
    BadMessage1(const BadMessage1& m):err(m.err){cout<<"call copy construct "<<m.err<<endl;}
    explicit BadMessage1(int e):err(e){cout<<"create err mess1 "<<e<<endl;};
    ~BadMessage1(){cout<<"destroy err mess "<<err<<endl;}
    virtual void Message(){cout<<"Err Message1 "<<err<<endl;};
};

class BadMessage2:public BadMessage1{
public:
    explicit BadMessage2(int e):BadMessage1(e){cout<<"create err mess2 "<<e<<endl;};
    ~BadMessage2(){cout<<"destroy err mess "<<err<<endl;}
    void Message() override {cout<<"Err Message2 "<<err<<endl;} ;
};


class Chatter{
private:
    std::string content;
public:
    explicit Chatter(const char * s):content(s){cout<<"chatter create "<<s<<endl;};
    ~Chatter(){cout<<"chatter destroy "<<content<<endl;}
    void show(){cout<<"disp con "<<content<<endl;}

};

#endif //FRIENDSEXCEPTION_ERROR_CLASS_H
