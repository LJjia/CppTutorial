/**
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 15:56 2021-08-20.
 * @Modify:
 */
#include <iostream>
#include "point.h"

using namespace std;
void point_test(){
    int *pn=new int;
    *pn=1000;
    cout<<"Test point "<<endl;
    cout<<"point addr "<<pn<<" value "<<*pn<<" size "<< sizeof(pn)<<endl;
    // delete和free 是否都可以用于释放new申请的指针,不知道,回去用linux的用valgrind试一下
//    free(pn);
    cout<<"free end";
    delete pn;
    int *plist=new int[10];
    cout<<" sizeof int[10] "<< sizeof(int[10])<<endl;
    memset(plist,0, sizeof(int[10]));
    // 中间带上[] 表示删除整个数组,而不是单独一个数组元素
    delete [] plist;
    cout<<"---------insert a break-------"<<endl;
    int narray[3][5]{};
    //array 将解释为行指针,每次+1移动20个地址,即5*sizeof(int)
    cout<<"addr "<<narray<<" "<<narray+1<<endl;
//    delete [] (plist+1);
    int array_size=10;
    // 使用变量进行new申请数组,动态联编
    int *pan=new int[array_size];
    cout<<"dyn new array addr "<<pan<<endl;
    const char *pConst="helloworld";
    cout<<"test start "<<pConst<<endl;
    //不可修改常量字符串的值,否则会引起signal 10(用户自定义信号) 异常.
//    pConst[0]='K';
    cout<<"test change const str"<<pConst<<endl;
}
