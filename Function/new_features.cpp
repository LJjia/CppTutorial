/**
 * @Author: Jialiangjun
 * @Description:C++新特性
 * @Date: Created on 16:51 2021-09-07.
 * @Modify:
 */
#include "new_features.h"
#include <iostream>
using namespace std;




inline int add(int x,int y){
    int c=x+y;
    return c;
}

void UseInlineFunc(){
    int c=0;
    c=add(10,15);
    cout<<"inline func "<<c<<endl;
}

void swapr(int &a,int &b){
    int tmp=a;
    a=b;
    b=tmp;
}

/*!
 * 引用做参数时,仅当引用指明const类型时,外部才可以传入表达式,或者类型不匹配的变量
 * 此时编译器将在函数调用时新创建一个变量,此变量用作函数入参的引用
 * 并不会修改原先不匹配的类型变量,但是说实话函数使用const定义形参,函数内部也不会修改这个变量
 * @param x
 * @return
 */
double refcube(const double & x){

    return x*x*x;
}

struct free_throws{
    int x;
    int y;

};

/*!
 * 在函数内部申请内存,返回申请内存的引用,需要在外部释放这个内存,
 * 但是到了外部,外部看起来输出值是一个引用,如何释放呢,不可以直接调用delete
 * @param ft
 * @return
 */
 free_throws & clone(free_throws& ft){
     auto pt=new free_throws;
     *pt=ft;
     return *pt;
 }

 /*!
  *这个函数的特点在于返回值是一个const类型,说明这个函数不可以做左值
  * 也就是说,不存在 free_throws tmp; clone_ret_const(ft)=tmp;这种奇怪的写法,最后哪句相当于是结构体之间赋值
  * @param ft
  * @return const引用
  */
const free_throws & clone_ret_const(free_throws& ft){
    auto pt=new free_throws;
    *pt=ft;
    return *pt;
}

void UseReference(){
    int a=10;
    double m=2,n=2;
    int *pInt=&a;
    // 这样定义ref还是a的引用
    int &ref=*pInt;
    double dRet=0;
    // 引用实现后,ref和相当于重名,&ref表示ref引用的变量(a)的地址.而不是引用变量(ref)的地址.
    cout<<"reference "<<&a<<" "<<&ref<<endl;

    int x=10,y=20;
    cout<<"before change "<<x<<" "<<y<<endl;
    swapr(x,y);

    cout<<"after change "<<x<<" "<<y<<endl;
    dRet=refcube(m);
    cout<<"double "<<dRet<<" "<<m<<endl;
    free_throws ft_1={10,20};
    free_throws ft_2{};
    free_throws & ft_ref=clone(ft_1);
    cout<<"clone "<<ft_ref.x<<" "<<ft_ref.y<<endl;

}

#include "name_space.h"
void TestNewFeature(){
//    UseInlineFunc();
//    UseReference();
//    using person::personality;
    using person::PtPersonality;
    PtPersonality();

}