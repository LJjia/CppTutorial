/**
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 16:31 2021-09-02.
 * @Modify:
 */
#include <iostream>
#include <string>
#include <array>

using namespace std;

unsigned int CalcFactorial(unsigned int x){
    if(x==0){
        return 1;
    } else{
        return x*CalcFactorial(x-1);
    }
}


/*!
 * 求一个数的立方
 * @param x
 * @return
 */
double cube(double x){
    return x*x*x;
}

void  testInputString(string * in){
    cout<<"Test str :"<<in[0]<<endl;

}

void TestArray(array<string,4> *in){
    for(int i=0;i<4;i++){
        cout<<i<<" :"<<(*in)[i]<<endl;
    }

}

void TestFuncParam(){
    int x=2;
    int y=1;
    int m=1,n=1;
    double dRet=0;
    array<string,4> rank{"First","second","third","fourth"};
    TestArray(&rank);
    unsigned int uFactorial=CalcFactorial(5);
    cout<<"calc 5! "<<uFactorial<<endl;

//    dRet=cube(x);
//    cout<<" cube "<<dRet<<endl;

}

