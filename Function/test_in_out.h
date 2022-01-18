/**
 * @File: test_in_out
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 20:00 2021-11-09.
 * @Modify:
 */
#ifndef FUNCTION_TEST_IN_OUT_H
#define FUNCTION_TEST_IN_OUT_H


#include <iostream>
using std::endl;
using std::cout;

class Obj {
private:
    int data;
public:
    Obj(int a=0):data(a){cout<<"call obj constructor "<<a<<endl;};
    ~Obj(){cout<<"call destructor "<<data<<endl;};
    Obj(const Obj & obj):data(obj.data){cout<<"call copy constructor ori "<<data<<endl;}
    Obj &operator=(const Obj &obj){cout<<data<<" call assign "<<endl;data=obj.data;return *this;}
    friend std::ostream &operator<<(std::ostream & os,const Obj &ob);
};


#endif //FUNCTION_TEST_IN_OUT_H
