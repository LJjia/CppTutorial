/**
 * @File: adapter
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 16:34 2021-11-13.
 * @Modify:
 */
#ifndef NEWCPP_ADAPTER_H
#define NEWCPP_ADAPTER_H

#include <iostream>
using std::cout;
using std::endl;
/*
template <typename  T,typename F>
T use_f(T v,F f){
    static int count=0;
    count++;
    cout<<" use_f count="<<count<<" count Addr:"<<&count<<endl;
    return f(v);
};*/


template <typename T>
T use_f(T v,std::function<T(T)> f){
    static int count=0;
    count++;
    cout<<" use_f count="<<count<<" count Addr:"<<&count<<endl;
    return f(v);
}

#endif //NEWCPP_ADAPTER_H
