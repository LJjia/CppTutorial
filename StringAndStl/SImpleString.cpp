/**
 * @File: SImpleString
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 17:06 2021-11-03.
 * @Modify:
 */

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;



template <typename T,int n=12>
class A{
    T aData[n];
public:
    A()= default;
    void show(){cout<<"This is a"<<endl;}


};


template <typename T1,typename T2=int>
class B{
    T1 data1;
    T2 data2;
public:
    B():data1(0),data2(0){};
    void show(){cout<<"This is b"<<endl;}


};

void DispStringSomeFeature(){
    A<int> a;
    B<int> b1;
    B<int,double> b2;
    a.show();
    b1.show();
    b2.show();
    string s1("abc");
    cout<<"s1 size "<<s1.size()<<" cap "<<s1.capacity()<<endl;
    // 修改string 的字符串最小单元大小,修改仅对单个对象生效,对新申请的对象不生效
    s1.reserve(30);
    string s2("cde");
    cout<<"s1 size "<<s1.capacity()<<endl;
    cout<<"s2 size "<<s2.size()<<" cap "<<s2.capacity()<<endl;
}

void SimpleStringInit(){
    // 利用字符串的前n个字符初始化
    // 不够长也用n个字符初始化,可能造成之前的访问\0
    string s1("hello",8);
    cout<<"string init "<<s1<<endl;
    char szChar[]{"0123456789"};
    string s2(szChar);
    string s3(&szChar[2],&szChar[4]);
    string s4(s2,0,4);
    string s5(s2);
    string s6(20,'a');
    cout<<"disp string "<<endl;
    cout<<"s2 "<<s2<<endl;
    cout<<"s3 "<<s3<<endl;
    cout<<"s4 "<<s4<<endl;
    cout<<"s5 "<<s5<<endl;
    cout<<"s6 "<<s6<<endl;
    string s7(szChar,11);
    cout<<" s7 "<<s7<<endl;
    cout<<" s7 size "<<s7.size()<<endl;
    DispStringSomeFeature();

}


