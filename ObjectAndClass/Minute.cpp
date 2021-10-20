/**
 * @File: Minute
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 15:36 2021-09-25.
 * @Modify:
 */
#include "Minute.h"
#include <iostream>

using namespace std;

Minute::Minute(int t) {
    cout<<"int structure min"<<endl;
    minute=t;
    second=0;
}

Minute::Minute(double t) {
    cout<<"double structure min"<<endl;
    minute=int(t);
    second=int(60*(t-int(t)));
}

Minute::Minute(int min, int sec) {
    cout<<"2 param structure min"<<endl;
    minute=min+sec/60;
    second=sec%60;
}

/*!
 * 拷贝构造函数
 * @param t
 */
Minute::Minute(const Minute& t){
    printf("call copy structure\n");
    minute=t.minute;
    second=t.second;
}

std::ostream & operator<<(std::ostream & os,Minute & t){
    return os<<"minute "<<t.minute<<" second "<<t.second;
}

//Minute operator+(double t0,Minute & t1){
//    return Minute(t1.minute+int(t0),t1.second+int(60*(t0-int(t0))));
//}

Minute operator+(const Minute & t0,const Minute & t1){
    return Minute(t1.minute+t0.minute,t1.second+t0.second);
}
//
//Minute Minute::operator+(const Minute &t) {
//    return Minute(minute+t.minute,second+t.second);
//}
//
//Minute Minute::operator+(double t) {
//    return Minute(minute+int(t),second+int(60*(t-int(t))));
//}

//Minute::operator double() const {
//    return minute+double(second)/60;
//}

Minute Minute::operator-() const{
    return Minute(-minute,-second);
}

void TestMinute(){

    Minute t0=Minute();
    Minute t1=Minute();

    t1=t0+1.5;

    double ts=10.0;
    cout<<"--------------"<<endl;
    t1=10.0+t0;
    t1=10.0+12;
    Minute negative=-t1;
    cout <<"out time "<<t1<<endl;
    cout <<"out time "<<negative<<endl;

}