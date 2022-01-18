/**
 * @File: multiplicate_param
 * @Author: Jialiangjun
 * @Description:多参数列表
 * @Date: Created on 09:55 2021-11-14.
 * @Modify:
 */
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
void show_list(const T& value){
    std::cout<<value<<endl;
}

//void show_list(){
//    std::cout<<endl;
//}

template <typename T, typename ...Args>
void show_list(const T& value,const Args& ...args){
    std::cout<<value<<"("<<sizeof ...(args)<<") ,";
    show_list(args ...);
}


// 用于终止迭代的基函数
template<typename T>
void processValues(T arg)
{
    cout<<arg<<endl;
}

// 可变参数函数模板
template<typename T, typename ... Ts>
void processValues(T arg, Ts ... args)
{
    cout<<arg<<",";
    processValues(args ...); // 解包，然后递归
}






template<typename T>
void print(T & t){
    std::cout << "左值" << std::endl;
}

template<typename T>
void print(T && t){
    std::cout << "右值" << std::endl;
}

template<typename T>
void testForward(T && v){
    cout<<"addr "<<(void*)&v<<endl;
    print(1);
    print(v);
    print(std::forward<T>(v));
    print(std::move(v));
}

template <class T>
void printarg(T t)
{
    cout << t << endl;
}

template <class ...Args>
void expand(Args... args)
{
    int arr[] = {(printarg(args), 0)...};
}

void r1(const double &rx){cout<<"const ";print(rx);}
void r2(double &rx){cout<<"normal &";print(rx);}
void r2(const double &rx){cout<<"const normal &";print(rx);}
void r3(double &&rx){cout<<"normal &&";print(rx);}



void TestParamList(){
    show_list(1,2.5,"Test");
    show_list(1);
    testForward(1);
    int x=2;
    testForward(x);
    double y=10.0;
    cout<<"--------------------"<<endl;
    r3(y+1);


}



/*!
 * 模板类编写的可变参数求和函数,此函数为最终调用的终止函数
 * @tparam T
 * @param value
 * @return
 */
template <typename T>
T sum_t(T value){
    return value;
}

/*!
 * 可变参数模板类,用于求和
 * @tparam T
 * @tparam Args
 * @param value
 * @param arga
 * @return
 */
//template <typename T,typename ...Args>
//T sum_t(T value,Args ...arga){
//    return value+sum_t(arga...);
//}

template <typename ...Args>
double sum_t(double value,Args ...arga){
    return value+sum_t(arga...);
}


void TestSum(){
    auto ret=sum_t(1,2,3,4.5,5);
    cout<<"sum "<<ret<<endl;
}