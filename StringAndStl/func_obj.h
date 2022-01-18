/**
 * @File: func_obj
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 10:18 2021-11-07.
 * @Modify:
 */
#ifndef STRINGANDSTL_FUNC_OBJ_H
#define STRINGANDSTL_FUNC_OBJ_H

#include <iostream>
#include <functional>

using namespace std;
using std::cout;
using std::endl;

template <typename T>
bool bBig(const T &val1,const T &lim){
    return val1>lim;
}

template <typename T>
class TooBig{
private:
    T threshold;
public:
    TooBig(const T val=0):threshold(val){};
//    自己写大于小于函数
//    bool operator() (const T & val){return val>threshold;}
//    利用函数模板进行隐式构造
    bool operator() (const T& val) {return bBig<T>(val,threshold);}
};

#endif //STRINGANDSTL_FUNC_OBJ_H
