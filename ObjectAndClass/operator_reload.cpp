/**
 * @File: operator_reload
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 15:51 2021-09-22.
 * @Modify:
 */
#include "operator_reload.h"
#include <iostream>
using  namespace std;

Timer Timer::operator+(Timer & t) const {
    Timer sum=Timer(this->hour+t.hour,this->minute+t.minute);
    return sum;
}

Timer Timer::operator+(double t) const {
    Timer sum=Timer(this->hour+int(t),this->minute+int((t-int(t))*60));
    return sum;
}
//
//Timer operator+(double t1,Timer t0) {
//    Timer sum=Timer(t0.hour+int(t1),t0.minute+int((t1-int(t1))*60));
//    return sum;
//}

void  Timer::Show() const {
    cout<<"Hour "<<hour<<" Minute "<<minute<<endl;
}

ostream & operator<<(ostream & os, const Timer &t){
    return os<<"hour "<<t.hour<<" "<<"minute "<<t.minute;
}

void TestTimer(){
    Timer a(1,40);
    Timer b(1,40);
    Timer d(1,40);
    Timer c;
    c=a+b+b;

    // 或者下面这种写法,这种是函数调用的方法
//    c=a.operator+(b);
    c=c+2.5;
    c=2.5+c;
    c.Show();

    cout<<c<<" "<<15;

}