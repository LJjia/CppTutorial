/**
 * @File: storageclass
 * @Author: Jialiangjun
 * @Description:通过写入文件的方式存储类
 * @Date: Created on 09:23 2021-11-12.
 * @Modify:
 */
#ifndef PROCINOUT_STORAGECLASS_H
#define PROCINOUT_STORAGECLASS_H

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

/*!
 * 存储不带虚方法的类,查看存储的类大小
 */
class SaveClassNoVir {
    char name[8];
    int age;
    int grade;
public:
    explicit SaveClassNoVir(const char* n="Stu",int a=10,int g=1):name{0},age(a),grade(g){
        cout<<n<<" father constructor "<<endl;
        strncpy(name,n,8);
    }
    void show(){
        cout<<name<<" age "<<age<<" grade "<<grade<<endl;
    }
    virtual ~SaveClassNoVir()= default;

};

class SaveClassNoVirSon:public SaveClassNoVir{
    int height;
    const int len=255;
    static int slen;

public:
    explicit SaveClassNoVirSon(const char* n="Stu",int a=10,int g=1,int h=0):
    SaveClassNoVir(n,a,g),height(h){
        cout<<" son constructor "<<endl;

    }
    void disp(){
        cout<<"NoVirSon show:"<<height;
        SaveClassNoVir::show();
    }
    virtual ~SaveClassNoVirSon()= default;

};

int SaveClassNoVirSon::slen=254;


class SaveClassVir {
    char name[8];
    int age;
    int grade;
public:


    explicit SaveClassVir(const char* n="Stu",int a=10,int g=1):age(a),grade(g){
        cout<<n<<" father constructor "<<endl;
        strncpy(name,n,8);
    }
    virtual void show(){
        cout<<name<<" age "<<age<<" grade "<<grade<<endl;
    }
    virtual ~SaveClassVir()= default;

private:

};

class SaveClassVirSon:public SaveClassVir{
    int height;

public:
    explicit SaveClassVirSon(const char* n="Stu",int a=10,int g=1,int h=0):
            SaveClassVir(n,a,g),height(h){
        cout<<" son constructor "<<endl;

    }
    void show() override{
        cout<<"NoVirSon show:"<<height;
        SaveClassVir::show();
    }
    ~SaveClassVirSon()= default;

};


#endif //PROCINOUT_STORAGECLASS_H
