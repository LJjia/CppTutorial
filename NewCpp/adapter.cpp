/**
 * @File: adapter
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 16:34 2021-11-13.
 * @Modify:
 */
#include "adapter.h"


double triple(double d){return 3*d;}

void TestAdapt(){
    std::function<double (double)> adapt1(triple);

    cout<<"Use triple"<<endl;
    cout<<use_f<double>(4.2,triple)<<endl;
    cout<<"Use lambda"<<endl;
    cout<<use_f<double>(4.2,[](double d){return 2*d;})<<endl;
    typedef std::function<double (double)> adaptfun;
    cout<<"ret "<<adaptfun(triple)(12.5);
};