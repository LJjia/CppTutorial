/**
 * @File: rtti
 * @Author: Jialiangjun
 * @Description: 有关dynamaic_cast的转换
 * @Date: Created on 17:10 2021-11-02.
 * @Modify:
 */
#ifndef FRIENDSEXCEPTION_RTTI_H
#define FRIENDSEXCEPTION_RTTI_H


#include <iostream>
#include <string>
#include <exception>
#include <typeinfo>
using std::cout;
using std::endl;

class A {
private:
    std::string name;
public:
    A(const char *s):name(s){};
    virtual ~A()=default;
    // 这种子类调用的name方法是自己的
    virtual void Speak(){cout<<this->name<<" class A speak"<<endl;};


};

class B:public A{
public:
    B(const char *s):A(s){};
    virtual ~B()= default;
    void Speak() override {cout<<" class B speak"<<endl;};
    virtual void Say(){cout<<"class B Say"<<endl;}
};

class C:public B{
private:
    int pri;
public:
    C(const char *s):B(s),pri(100){};
    virtual ~C()= default;
    void Speak() override {cout<<" class C speak"<<endl;}
    void Say()override {cout<<"class C Say pri "<<pri<<endl;}
};


#endif //FRIENDSEXCEPTION_RTTI_H
