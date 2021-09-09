/**
 * @Author: Jialiangjun
 * @Description: 分支语句和逻辑运算符
 * @Date: Created on 09:27 2021-08-29.
 * @Modify:
 */
#include "state_operate.h"
#include <cctype>
#include <iostream>
#include <fstream>
using namespace std;
void TestCCtype(){
    char s='a';
    cout<<"check char "<<isalnum(s)<<" "<<isalpha(s)<<" "<< isdigit(s)<<endl;

}

/*!
 * 记一下switch语句的标准写法
 * @param a
 */
void TestSwitch(int a){
    switch (a){
        // case中无法输入浮点类型
        case 2:
            cout<<"a is 2"<<endl;
            break;
        case 3:
            cout<<"a is 3"<<endl;
            break;
        case 5:
            cout<<"a is 5"<<endl;
            break;
        default:
            // 如果没有default语句并且输入了错误的值,switch语句会直接退出,不会执行语句块
            cout<<"use invalid value ,exit!"<<endl;
            break;
    }
}

void TestInputStr2Int(){
    int x=0;
    int y=0;
    cout<<"input to x"<<endl;
    /*
     * cin 不会读取空格和回车键,所以如果输入数字,有两种方法
     * 1.输入20+回车 输入40+回车 显示 20 ,40
     * 2.输入20+空格+40+回车    显示20,40
     * cin遇到空格类似会自动停止一次读取,回车相当于处罚程序读取输入缓冲,读完20后,40留在缓冲内,
     * cin会继续读取缓冲中的内容,将40读入
     *
     * 而如果输入数字,类似会遇到错误,不会崩溃,但是无论输入单个字符还是一串字符 比如
     * 输入 a
     * 输入 abcd
     * 都会立刻停止cin输入(只输了一次,但是两次cin都停止),x和y的值不会修改,打印出来是0 0
     * 这是因为cin>>x 如果输入错误,比如输入字符,将会把这次的输入作废,并且置错误标记
     * 和EOF类似,需要调用cin.clear()清除错误标记,才可以再次读取输出
     * 但是读取的输入仍是上次的错误输入,
     * while(cin.get()!='\n')
        continue;
        这句话是读取
     * */

    cin>>x;
    cin.clear();
    while(cin.get()!='\n')
        continue;
    cin>>y;
    cout<<"value x "<<x<<" "<<(int)y<<endl;
}

/*!
 * 测试cin读取回车
 */
void TestCinGetEnter(){
    char szStr[80]{};
    char szStr2[80]{};
    goto OUT_STR;

    cin.get(szStr,80).get();
    cin.get(szStr2,80);
    OUT_STR:
    cout<<"enter line "<<szStr<<szStr2<<endl;
}

void TestFileOut(){
    ofstream outfile;
    outfile.open("output.txt");
    outfile<<"This is file try\n"<<"out something\n";
    outfile.close();
}
void TestFileIn(){
    // infile 类似cin对象,将输入读取到文件中
    ifstream infile;
    char szContent[120];
    infile.open("output.txt");
    cout<<"cin good?"<<cin.good()<<"\n";
    cout<<"check file open "<<infile.is_open()<<endl;
    while (infile.good()){

        cout<<"file content:"<<szContent<<endl;
        // 由于最后的文件内容读完后,还要再读一次才会触发EOF,而再读触发文件EOF,
        // 并且处罚eof的读取不会使szContent内容发生改变,因此读完后需要判断是否good,为good再输出
        infile>>szContent;

    }


    infile.close();
}

void TestState(){
//    TestCCtype();
//    TestInputStr2Int();
//    TestCinGetEnter();
//    TestFileOut();
    TestFileIn();

}
