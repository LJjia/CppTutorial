/**
 * @File: Minute
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 15:36 2021-09-25.
 * @Modify:
 */
#ifndef OBJECTANDCLASS_MINUTE_H
#define OBJECTANDCLASS_MINUTE_H

#include <iostream>

/*!
 * 计时单位,输入double类型值自动转换为60进制
 */
class Minute {
private:
    int minute;
    int second;
public:

    Minute(){minute=0;second=0;};
    Minute(double t);
    Minute(int t);
    Minute(int min,int sec);
//    Minute operator+(const Minute & t);
//    Minute operator+(double t);
    friend std::ostream & operator<<(std::ostream & os,Minute & t);
//    friend Minute operator+(double t0,Minute & t1);
    friend Minute operator+(const Minute & t0,const Minute & t1);
//    explicit operator double() const;
//    operator int();
    Minute operator-() const;

};


#endif //OBJECTANDCLASS_MINUTE_H
