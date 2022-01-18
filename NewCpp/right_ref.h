/**
 * @File: right_ref
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 15:10 2021-11-12.
 * @Modify:
 */
#ifndef NEWCPP_RIGHT_REF_H
#define NEWCPP_RIGHT_REF_H

#include <iostream>
class Useless {
    enum {NAME_LEN=16};
private:
    char szName[NAME_LEN];
    char *pc;
    int len;
public:
    Useless(const char *name,int num,char ele);
    ~Useless();
    Useless(const Useless & ins);
    Useless(Useless&& ins)noexcept;
    void show();
    void Add(){std::cout<<"*******Add func obj addr *********"<<this<<std::endl;len+=3;};
    Useless operator+(const Useless &u1)const;
    Useless& operator=(Useless &&u1) noexcept;
    Useless& operator=(const Useless &u1);
};

using std::cout;
using std::endl;

class A{
    int data=0;
public:
    void fn(int i){cout<<"class A int"<<endl;}
    void fn(double i){cout<<"class A double"<<endl;}
    void fn(void* i){cout<<"class A double"<<endl;}
};

class B:public A{
    int data=0;
public:
    using A::fn;
    void fn(int i){cout<<"class B int"<<endl;}
};

class C{
    int data;
public:
    explicit C(int d=0):data(d){};
    C(C &&ins)= default;
//    C &operator=(C &&ins)= default;
    void show(){std::cout<<"show "<<data<<std::endl;}

};

#endif //NEWCPP_RIGHT_REF_H
