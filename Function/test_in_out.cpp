/**
 * @File: test_in_out
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 20:00 2021-11-09.
 * @Modify:
 */
#include "test_in_out.h"

#define HERE(cnt) cout<<"----------------"<<__FUNCTION__<<"--------------------"<<cnt<<endl;

std::ostream &operator<<(std::ostream & os,const Obj &ob){
    return os<<ob.data;
}

void TestInputConst(const Obj& ob){
    HERE(0);
    cout<<"TestInputConst "<<ob<<endl;
    HERE(1);
}

const int TestOut(){
    int a=10;
    return a;
}

const Obj & TestOutObj(Obj & ob){
    Obj a;
    return ob;
}

void TestInOut(){
#if 0
    Obj one;
    HERE(0);
    TestInputConst(10);
    HERE(1);
    TestInputConst(one);
    HERE(2);
    cout<<endl<<endl;
    HERE(3);
    const int a=TestOut();
    int b=TestOut();
    cout<<"a "<<a<<endl;
    b++;
    cout<<"b "<<b<<endl;
#endif
    Obj one;
    Obj two(20);
    one=TestOutObj(two);
    cout<<one<<" --- "<<endl;
}

