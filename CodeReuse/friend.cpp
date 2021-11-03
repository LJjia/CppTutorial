/**
 * @File: friend
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 17:09 2021-10-27.
 * @Modify:
 */
#include <array>
#include "friend.h"

// 泛初始化,一次将初始化所有类型下的static int ct变量
// 每个类型独享一个static变量
template <typename T>
int HasFriend<T>::ct=0;

template <typename T>
void counts(){
    cout<<"cout size "<<sizeof(HasFriend<T>)<<endl;
    cout<<"cout cnt  "<<HasFriend<T>::ct<<endl;
}



//template <typename T>
//void reports(HasFriend <T> &hf){
//    cout<<"report generic "<<hf.items<<endl;
//}

template <typename T>
void formalparam(T in){
//    cout<<"cout double "<<HasFriend<double>::ct<<endl;
    cout <<"input model "<<in<<" size "<<sizeof(in)<<endl;
    cout<<"cout model  "<<HasFriend<T>::ct<<endl;
}

// 针对模板实例化的特定函数
template <typename T>
void reports(HasFriend<T> &hf){
    cout<<"report items "<<hf.items<<endl;
}

template <typename C> void allin(C c){
    cout<<"input c"<<c<<endl;
    cout<<HasFriend<int>::ct<<" "<<HasFriend<double>::ct<<" "<<endl;
}

void TestTemplateFriend(){
    HasFriend<int > n1(5);
    HasFriend<int > n2(10);
    HasFriend<double>d(15.5);
    counts<int>();
    counts<double>();
    reports<int>(n1);
    reports(d);
    formalparam(5);
    allin(10.5);


    double d1[]{1.0,2.0};
    double d2[]{1.0,2.0};
    double d3[]{1.0,2.0};
    std::array<double *,3> aDouble{};
    aDouble[0]=d1;
    aDouble[1]=d2;
    aDouble[2]=d3;
    cout<<"double array addr "<<aDouble[0]<<endl;
    cout<<"double array addr "<<aDouble[1]<<endl;
    cout<<"double array addr "<<aDouble[2]<<endl;

}

