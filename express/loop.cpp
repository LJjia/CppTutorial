/**
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 14:31 2021-08-21.
 * @Modify:
 */
#include "loop.h"
#include <iostream>
#include <string>
#include <zconf.h>

using namespace std;

void TestLoop(){
    int a=0;
    cout<<"0 disp "<< true<<" "<<(a>1)<<" "<<(a==10)<<endl;
    // cout默认将true和判断语句(包括><和==等,不包括赋值和运算)的结果返回 0 1,设置下面的,将默认返回true false
    // 可以是ios::boolalpha或者 ios_base::boolalpha
    cout.setf(ios_base::boolalpha);
    cout<<"1 disp "<< true<<" "<<(a>1)<<" "<<(a==10)<<endl;


    cout<<"Use range for"<<endl;
    int prices[5]={2,4,8,2,1};
    for( auto x : prices){
        cout<<"price :"<<x<<endl;
    }
    cout<<"---------------"<<endl;
    for( auto& x : prices){
        x++;
    }
    cout<<"after change ---------------"<<endl;
    for( auto& x : prices){
        cout<<"price :"<<x<<endl;
    }

    // 初始化二维数组
    int two_array[2][3]={
            {1,2,3},
            {4,5,6},
    };
    // 指针数组,字符串数组,string数组
    const char *pStr[3]={
            "jia",
            "li",
            "wang",
    };
    const char aStr[3][10]={
            "jia",
            "li",
            "wang",
    };
    string sStr[3]={
            "jia",
            "li",
            "wang",
    };
}


int GetInputWordNum(){
    int cnt=0;
    char word[1024]{'d',};
    char word2[1024]{'d','a'};
    cout<<strncmp(word,word2,1)<<endl;
    cin>>word;
    cout<<" input word :"<<word<<endl;
    while(strcmp(word,"done")){
        cnt++;
        cin>>word;
        cout<<" input word :"<<word<<endl;
        sleep(1);

    }
    // < 运算符从左向右结合 ,这句语句的意思是 (1<cnt)<20
    if(1<cnt<20){
        ;
    }
    cout<< "input word num "<<cnt<<endl;
    return 0;
}