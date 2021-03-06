/**
 * @File: MyStrings
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 10:47 2021-09-29.
 * @Modify:
 */
#include "MyStrings.h"
#include <iostream>
#include <cstring>
using namespace std;
// 很特殊,私有数据维度static变量可以这样赋值
int MyStrings::sNumString=0;

MyStrings::MyStrings() {
    cout<<"default structure"<<endl;
    // 使用new char[]这种形式方便delete的时候可以delete []
    pStr=new char[1];
    pStr[0]='\0';
    sNumString++;
}

MyStrings::MyStrings(const char *pChar) {
    cout<<"cchar structure"<<pChar<<endl;
    len=strlen(pChar);
    pStr=new char[len+1];
    strcpy(pStr,pChar);
    sNumString++;
}

MyStrings::~MyStrings() {

    if(pStr){
        printf("free object %s\n",pStr);
    }
    delete []pStr;
    sNumString--;
}

/*!
 * 拷贝构造函数,初始化赋值的时候可能调用
 * @param str0
 */
MyStrings::MyStrings(const MyStrings &str0) {
    cout<<"copy structure source "<<str0.pStr<<endl;
    len=strlen(str0.pStr);
    pStr=new char[len+1];
    strcpy(pStr,str0.pStr);
    sNumString++;
}

/*!
 * c字符串到类对象的复制,如果单参数构造可行,这个函数似乎也不需要重载?
 * 这么重载的原因是通过默认构造再赋值的效率不及运算符直接重载高
 * @param pChar
 * @return 对象本身的引用,使得连等有效
 */
MyStrings& MyStrings::operator=(const char *pChar) {
    delete []pStr;
    len=strlen(pChar);
    pStr=new char[len+1];
    strcpy(pStr,pChar);
    sNumString++;
    return *this;
}

/*!
 * 复制运算符重载函数,注意是赋值的时候调用这个函数,而不是像拷贝构造初始化的时候调用
 * 但是有些编译器实现也会导致初始化的时候调用拷贝构造和赋值重载
 * @param str0
 * @return
 */
MyStrings& MyStrings::operator=(const MyStrings &str0) {
    // 避免自己赋值个给自己造成指针释放
    if(this==&str0){
        return *this;
    }
    printf("call operator func equal %s\n",pStr);
    delete []pStr;
    len=strlen(str0.pStr);
    pStr=new char[len+1];
    strcpy(pStr,str0.pStr);
    return *this;
}

/*!
 * 比较函数作为友元函数可以在面对c字符串和MyStrings类做比较的时候,重载运算符,在函数参数内部完成c字符串到对象的构造
 * 大于就是大于,不包括等于
 * @param str1
 * @param str2
 * @return
 */
bool operator>(const MyStrings &str1, const MyStrings &str2) {
    return std::strcmp(str1.pStr,str2.pStr)>0;
}

/*!
 * 不包括等于
 * @param str1
 * @param str2
 * @return
 */
bool operator<(const MyStrings &str1, const MyStrings &str2) {
    return std::strcmp(str1.pStr,str2.pStr)<0;
}

bool operator==(const MyStrings& str1,const MyStrings& str2){
    return std::strcmp(str1.pStr,str2.pStr)==0;
}

const MyStrings operator+(const MyStrings& str1,const MyStrings& str2){
    int length;
    char* pNew= nullptr;
    length=str1.len+str2.len;
    pNew=new char[length+1];
    strcpy(pNew,str1.pStr);
    strcpy(&pNew[str1.len],str2.pStr);
    pNew[length]=0;
    MyStrings newObj(pNew);//=MyStrings(pNew);
    return newObj;

}

/*!
 * 重载取索引运算符
 * 对于非const对象,可做左值
 * @param i
 * @return
 */
char& MyStrings::operator[](int i) {
    return pStr[i];
}

/*!
 * 重载索引运算符,面对const对象,非const的引用无法使用,因此需要单独系写一个方法
 * 此表达式不可做左值
 * @param i
 * @return
 */
const char& MyStrings::operator[](int i) const {
    return pStr[i];
}

std::ostream& operator<<(std::ostream & os,const MyStrings& str0){
    return os<<str0.pStr;
}

/*!
 * 统计某个字符在本字符串中出现了几次
 * @param c
 * @return
 */
int MyStrings::StaticAppearTimes(char c) const{
    int cnt=0;
    char *pChar= 0;
    pChar=pStr;
    if(pChar== nullptr){
        return 0;
    }
    while(*pChar!='\0'){
        pChar++;
        if(*pChar==c){
            cnt++;
        }
    }
    return cnt;
}

/*!
 * 字符转大写,修改本对象字符串,返回对象本身
 * @return
 */
const MyStrings& MyStrings::upper(){
    for(int i=0;i<len;i++){
        if(islower(pStr[i])){
            pStr[i]=toupper(pStr[i]);
        }
    }
    return *this;
}

/*!
 * 字符转小写,修改对象字符串,并返回对象本身
 * @return
 */
const MyStrings& MyStrings::low(){
    for(int i=0;i<len;i++){
        if(isupper(pStr[i])){
            pStr[i]=tolower(pStr[i]);
        }
    }
    return *this;
}


int MyStrings::HowMany() {
    return sNumString;
}


void DispMyStrings(MyStrings data){
    cout<<data<<endl;
}

void InputPoint(const MyStrings &pStrings){
    cout<<"===len "<<pStrings.length()<<endl;
}

void TestMyStrings() {
    {
        // 下面这句话相当于 MyStrings str1=MyStrings("12345");
        // 调用const char*参数类型的构造函数
        MyStrings str1 = "12345";
        MyStrings str2="67890";
        MyStrings str3="24863";
        printf("----------\n");
        str1=str2=str3;
        printf("----------\n");
        bool bBool;
        bBool=str1>str2;
        cout<<"str1 > str2?"<<bBool<<endl;
        bBool=(str1==str2);
        cout<<"str1 == str2?"<<bBool<<endl;
        bBool=str1<str2;
        cout<<"str1 < str2?"<<bBool<<endl;
        bBool=str1==str3;
        cout<<"str3 == str1?"<<bBool<<endl;
        cout<<"str 1 "<<str1<<" *** "<<"str 2 "<<str2<<endl;
        cout<<"idx "<<str1[0]<<" "<<str1[1]<<endl;
        DispMyStrings(str1);
    }
    cout<<"how many call "<<MyStrings::HowMany()<<endl;
    printf("build last strings \n");
    MyStrings last;
    MyStrings part1="1234";
    MyStrings part2="7890";
    last=part1+part2+"last";

    cout<<"+++++"<<last<<endl;
    MyStrings testStr="AaaaBbCCd";
    cout<<testStr<<endl;
    cout<<"static a appear times "<<testStr.StaticAppearTimes('a')<<endl;
    cout<<testStr.low()<<endl;
    cout<<testStr.upper()<<endl;
    cout<<"------------"<<endl;
//    last=part1+part2;
    part1+part2;
    cout<<"-------------"<<endl;

    InputPoint("123");
}


/*!
 * 返回对象引用的函数
 * @return
 */
MyStrings RetObjRef(){
    MyStrings lo="123";
    cout<<"quit func obj"<<endl;
    return lo;
}

int& RetIntRef(int &r){
    int a=0;
    cout<<"quit func int"<<endl;
    return r;
}

/*!
 * 测试函数返回值
 */
void TestFuncRet(){
    cout<<"=============\n"<<"Test func ret"<<endl;
    int a=10;
    int b=5;
    a=RetIntRef(b);
    cout<<"outer func run end "<<a<<endl;
}
