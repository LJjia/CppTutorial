/**
 * @File: other_lib
 * @Author: Jialiangjun
 * @Description: cpp 16.7 其他库
 * @Date: Created on 16:05 2021-11-07.
 * @Modify:
 */

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <functional>
#include <array>
#include <valarray>

using namespace std;
using std::cout;
using std::endl;


void TestValArray(){
    valarray<int> a1{1,2,3,4,5,6};
    // 虽然slice返回的是一组值,但是
    // 不可使用valarray<int> a2(1,2,3,4,5,6);这种初始化,
    // valarray为slice定制了个构造函数
    // slice(0,2,3),0表示起始地址,2表示元素个数,3表示跨距
    valarray<int> extract(a1[slice(0,2,3)]);

    for(int* _i=begin(a1);_i!=end(a1);++_i){
        cout<<*_i<<" ";
    }
    cout<<endl<<"-------"<<endl;
    for(int* _i=begin(extract);_i!=end(extract);++_i){
        cout<<*_i<<" ";
    }
    cout<<endl<<"-------"<<endl;
    shared_ptr<double> pd{new double};
/*
    vector<int> v1{0,1,2,3};
    v1.push_back(9);
    cout<<"v1 capacity"<<v1.capacity()<<endl;
    cout<<v1[3]<<" "<<v1[5]<<" "<<v1[6]<<endl;
    int c=-1;
    c=v1.at(5);
    cout<<c;*/
}




