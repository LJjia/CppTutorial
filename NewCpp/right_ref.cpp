/**
 * @File: right_ref
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 15:10 2021-11-12.
 * @Modify:
 */
#include "right_ref.h"

#include <cstring>
#include <cctype>
#include <iostream>

using std::cout;
using std::endl;

Useless::Useless(const char *name, int num, char ele) {
    cout<<name<<" base construct num "<<num<<" char "<<ele<<" self:"<<this<<endl;
    strncpy(szName,name,NAME_LEN);
    len=num;
    pc=new char[len];
    if(!isalpha(ele)){
        cout<<"input not char!! "<<ele<<endl;
    }
    for(int i=0;i<len;i++){
        pc[i]=ele;
    }
}

Useless::Useless(const Useless &ins) {
    cout<<" copy constructor src "<<ins.szName<<" Addr "<<(void*)ins.pc<<" self:"<<this<<endl;
    len=ins.len;
    pc=new char[len];
    for(int i=0;i<len;i++){
        pc[i]=ins.pc[i];
    }
    strncpy(szName,ins.szName,NAME_LEN);
}

/*!
 * 移动构造函数
 * @param ins
 */
Useless::Useless(Useless &&ins) noexcept{
    cout<<"move constructor src:"<<ins.szName<<" Addr "<<(void*)ins.pc<<" self:"<<this<<endl;
    len=ins.len;
    pc=ins.pc;
    ins.pc=0;
    ins.len=0;
    strncpy(szName,ins.szName,NAME_LEN);
    memset(ins.szName,0,NAME_LEN);
}

/*!
 * 移动赋值函数
 * @param u1
 * @return
 */
Useless& Useless::operator=(Useless &&u1) noexcept {
    if(&u1==this){
        return *this;
    }
    cout<<"call  move operator="<<endl;
    // 先把自己的删除,再取别人的
    delete []pc;
    strncpy(szName,u1.szName,NAME_LEN);
    len=u1.len;
    pc=u1.pc;
    u1.len=0;
    u1.pc= nullptr;
    memset(u1.szName,0,NAME_LEN);
    return *this;
}


/*!
 * 重载赋值运算符
 * @param u1
 * @return
 */
Useless& Useless::operator=(const Useless &u1)  {
    if(&u1==this){
        return *this;
    }
    cout<<"call normal operator="<<endl;
    // 先把自己的删除,再取别人的
    delete []pc;
    strncpy(szName,u1.szName,NAME_LEN);
    len=u1.len;
    pc=new char[len];
    for(int i=0;i<len;i++){
        pc[i]=u1.pc[i];
    }
    return *this;
}

Useless::~Useless() {
    cout<<szName<<" destroy Addr "<<(void*)pc<<" self:"<<this<<endl;
    delete []pc;

}

void Useless::show() {
    cout<<szName<<" Addr "<<(void *)pc<<" disp num "<<len<<" "<<pc<<endl;
}

Useless Useless::operator+(const Useless &u1) const {
    cout<<"call operator+ func start"<<endl;
    Useless tmp("Add",len+u1.len,0);
    int idx=0;
    for(idx=0;idx<len;idx++){
        tmp.pc[idx]=pc[idx];
    }
    for(;idx<len+u1.len;idx++){
        tmp.pc[idx]=u1.pc[idx-len];
    }
    cout<<"call operator+ func end"<<endl;
    return tmp;
}


void TestrightRef(){
    Useless one("one",10,'a');
    Useless two("two",20,'b');
//    Useless three("three",30,'b');
    cout <<"+++++Test add +++++"<<endl;
    Useless three(one+two);
//    (one+two).show();
//    three= std::move(one+two);
    cout <<"+++++ add End+++++"<<endl;
//    three.show();
    B b;
    b.fn(10);
    b.fn(nullptr);

}

#include <right_ref.h>

template<typename T>
void print(T & t){
    std::cout << "左值" << std::endl;
    t.Add();
}

template<typename T>
void print(T && t){
    std::cout << "右值" << std::endl;
    t.Add();
}

template <typename T>
void Input(T&& ins){
    cout<<"Input right left Test"<<endl;
    print(std::forward<T>(ins));
//    print(ins);
}

void TestRightValueParam(){
    Useless one("one",10,'o');
    Useless two("two",10,'t');
//    Useless&&three=one+two;
//    three.show();
    Input(one+two);
    cout<<"end run end"<<endl;
//    Input(20+1);
//    three.show();

}