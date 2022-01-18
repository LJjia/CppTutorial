/**
 * @File: func_obj
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 10:18 2021-11-07.
 * @Modify:
 */
#include <vector>
#include <set>
#include <map>
#include "func_obj.h"



void TestFuncObj(){
    TooBig<int> big1(50);
    cout<<"bigger ? "<<big1(100)<<endl;

    plus<double>add;
    double x=add(12,14.5);
    cout<<"use default func x value "<<x<<endl;

    const int LIM=5;
    double arr1[LIM]{2,4,6,8,10};
    vector<double> v1(arr1,arr1+LIM);
    vector<double> v2(LIM,1);
    plus<double > f2;
    transform(v1.begin(),v1.end(),ostream_iterator<double,char>(cout," "),bind1st(f2,5.5));

}



