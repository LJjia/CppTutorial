/**
 * @File: worker
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 11:29 2021-10-24.
 * @Modify:
 */
#ifndef CODEREUSE_WORKER_H
#define CODEREUSE_WORKER_H

#include <iostream>
#include <string>
#include <array>
#include <cstring>
using std::endl;
using std::cin;
using std::cout;
using std::string;
/* 类继承关系:
Worker(基类)
Waiter(派生类) Singer(派生类)
*/

class Worker
{
private:
    string FullName;
    long id;
public:
    Worker() :FullName("no one"), id(0L) {};
    Worker(const string& s, long n) :FullName(s), id(n) {};
    virtual ~Worker()=0;
    virtual void set();
    virtual void show() const;
};


class Waiter:virtual public Worker{
private:
    int panache;
public:
    Waiter():Worker(),panache(0){};
    Waiter(const string& s,long n,int p=0):Worker(s,n),panache(p){};
    Waiter(const Worker & wk,int p=0):Worker(wk),panache(p){};
    void set() override;
    void show() const override;
};

class Singer:virtual public Worker{
private:
    enum {other,alto,bass,tensor};
    int voice;
public:
    Singer():Worker(),voice(other){};
    Singer(const string &s,long n,int v=other):Worker(s,n),voice(v){};
    Singer(const Worker& wk,int v=other):Worker(wk),voice(v){};
    void set() override;
    void show() const override;
};

class SingerWaiter:public Singer,public Waiter{
public:
    SingerWaiter(const Worker &wk,int p,int v):Worker(wk),Singer(wk,v),Waiter(wk,p){};
    void call();
    void set() override;
    void show() const override;
};

#endif //CODEREUSE_WORKER_H
