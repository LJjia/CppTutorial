/**
 * @File: TestClassTp
 * @Author: Jialiangjun
 * @Description: 测试类模板
 * @Date: Created on 14:09 2021-10-26.
 * @Modify:
 */


#include "stacktp.h"
#include <array>

void TestStackTemplate(){
    Stack<int >s1;
    // 必须显式指定类型来创建类模板
    s1.push(1);
    s1.push(2);
    s1.push(3);
    Stack<int >s2;
    s2=s1;
    s1.DispItems();
    s2.DispItems();

//    const One<const int >one;
    One<int >one1;
    int ret=0;
    const int cret=0;
//    const int cret=one.first();

//    ret=one.first();
    ret=((const One<const int> &)one1).first();
    cout<<"value "<<ret<<" "<<cret;
}


/*!
 * 测试类嵌套模板
 */
void TestClassNestModel(){
    beta<double> guy(3.5,2);
    double ret=guy.blab(2.0,2.5);
    cout << "ret "<<ret<<endl;
    guy.Show();

    Crab<Stack> cb;
    int a=0;
    double b=0;
    cb.push(a,b);
    cb.pop(a,b);

}

