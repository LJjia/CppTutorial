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


//默认参数声明
void UseDefaultInput(int x);

/*!
 * 默认参数定义
 * @param x
 */
void UseDefaultInput(int x=10){
    cout<<"input x"<<x<<endl;
}

/*!
 * 使用默认参数
 */
void TestDefaultParam(){
    UseDefaultInput();
}

void drib(char *pChar){
    cout<<"input "<<pChar<<endl;
}

void drib(const char *pChar){
    cout<<"const input "<<pChar<<endl;
}

void TestNum(char *pChar,int num=5);
//void TestNum(char *pChar);

void TestOverload(){
    char szPath[]="abcdefg";
    drib(szPath);
    drib("1234");
    TestNum(szPath);
}

void TestNum(char *pChar,int num){
    cout<<"inut pChar num "<<pChar<<" "<<num<<endl;
}

//void TestNum(char *pChar){
//    cout<<"inut pChar num "<<pChar<<" "<<endl;
//}

template <typename T>
void SwapTemplate(T & a,T & b){
    T tmp;
    tmp=b;
    b=a;
    a=tmp;
}

//template <typename T>
//void SwapTemplate(T *a,T *b){
//    T tmp;
//    tmp=*b;
//    *b=*a;
//    *a=tmp;
//}

struct Job{
    char name[16];
    int salary;
};

template <> void SwapTemplate<Job>(Job & a,Job & b){
    int tmp=0;
    tmp=a.salary;
    a.salary=b.salary;
    b.salary=tmp;
}

template <typename T1,typename T2>
auto Add(T1 a,T2 b)->decltype(a+b){
    typedef decltype(a+b) apbtype;
    return a+b;
}


//template <> void SwapTemplate<Job>(Job & a,Job & b);

template <typename T>void recycle(T t){
    decltype((t)) refT=t;
    cout<<"refT "<< refT<<" "<<t<<endl;
    refT=20;
    cout<<"change "<< refT<<" "<<t<<endl;
    cout<<"use a type"<<endl;
}
template <typename T>void recycle(T* t){

    cout<<"use a type point"<<endl;
}
struct blot{
    int a;
    char sz[20];
};


int procInt(int a,int b){
    return a+b;
}

int PtString(const char * pChar="LJjia");

int PtString(const char * pChar){
    cout<<"Use string "<<pChar<<endl;
    return 0;
}


void TestTemplate(){
    blot tmp{10,"123"};
    int x=10;
    recycle(x);
    double a=0,b=2.5;
    int c=procInt(a,b);

    cout<<"**"<<Add(1,2.5)<<endl;
    PtString();
    PtString("nice work");
    string lower="abcd";
    for (int j=0;j<lower.size();j++){
        lower[j]=toupper(lower[j]);
    }
    cout<<lower<<endl;



}





