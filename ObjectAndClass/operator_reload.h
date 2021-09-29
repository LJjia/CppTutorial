/**
 * @File: operator_reload
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 15:51 2021-09-22.
 * @Modify:
 */
#ifndef OBJECTANDCLASS_OPERATOR_RELOAD_H
#define OBJECTANDCLASS_OPERATOR_RELOAD_H

#include <iostream>


/*!
 * 时间重载对象
 */
class Timer {
public:
    Timer(){
        hour=minute=0;
    }
    Timer(int h,int m){
        hour=h;
        minute=m;
        hour+=minute/60;
        minute=minute%60;
    }
    Timer operator+(Timer & t) const ;
    Timer operator+(double t) const ;
    // 类定义内,默认定义为内联函数
    friend Timer operator+(double t1,Timer t0) {
        return t0+t1;
    }
    friend std::ostream & operator<<(std::ostream & os, const Timer &t);
    void  Show() const ;

private:
    int hour;
    int minute;

};


#endif //OBJECTANDCLASS_OPERATOR_RELOAD_H
