/**
 * @File: fruits
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 14:40 2021-10-20.
 * @Modify:
 */
#ifndef CLASSINHERIT_FRUITS_H
#define CLASSINHERIT_FRUITS_H

#include <string>
#include <iostream>


class Element{
public:
    Element(){std::cout<<"Ele construct "<<std::endl;}
    ~Element(){std::cout<<"Ele destroy "<<std::endl;}

private:
    int tmp;
};

enum COLOR{
    C_RED,
    C_GREEN,
    C_BLUE,
};

class Fruits {
private:
    std::string name;
    int caloris;
    int weight;
public:
    explicit Fruits(const std::string &n="fruits",int kj=0,int w=0);
    virtual ~Fruits();
//    ~Fruits();
    int kg();
    virtual int Usage();
    virtual void SameName(int x);
    virtual void SameName(int x,int y);

protected:
    void ProtectWay(){std::cout<<"---protect way--- "<<std::endl;}
};

class Apple:public Fruits{
private:
    int color;
public:
    explicit Apple(const std::string &n="apple",int kj=0,int w=0,int c=C_RED);
    explicit Apple(const Fruits &f,int c=C_RED);
    void SameName(int x) override;
    void SameName(int x,int y) override;
    int Usage() override;
//    ~Apple(){std::cout<<"apple destroy"<<std::endl;};
    Element ele;
};

class BaseShape{
public:
    explicit BaseShape(){std::cout<<"Base shape default construct"<<std::endl;}
    virtual int Area() const =0;
    void Hide(){std::cout<<"Base hide"<<std::endl;}
    void Hide(int a){std::cout<<"Base hide 1param"<<std::endl;}
    void Hide(int a,int b){std::cout<<"Base hide 2param"<<std::endl;}
    virtual BaseShape & operator=(const BaseShape &){std::cout<<"call Base equal operator"<<std::endl;return *this;}
};
class Circle:public BaseShape{
private:

public:
    explicit Circle(){std::cout<<"circle construct "<<std::endl;}
    void IsCircle(){std::cout<<"is acircle "<<std::endl;}
    virtual int Area() const{std::cout<<"is a son class "<<std::endl;return 1;};
    void Hide(){BaseShape::Hide();BaseShape::Hide(1);BaseShape::Hide(1,2);;std::cout<<"Cicle hide"<<std::endl;}
    Circle & operator=(const Circle &){std::cout<<"call Circle equal operator"<<std::endl;return *this;}
};

class AppleTree:public Apple{
public:
    void TestPt();

};

#endif //CLASSINHERIT_FRUITS_H
