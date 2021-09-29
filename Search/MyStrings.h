/**
 * @File: MyStrings
 * @Author: Jialiangjun
 * @Description:自定义strings类型
 * @Date: Created on 10:47 2021-09-29.
 * @Modify:
 */
#ifndef SEARCH_MYSTRINGS_H
#define SEARCH_MYSTRINGS_H

#include <iostream>
class MyStrings {
public:
    MyStrings();
    MyStrings(const char * pChar);
    // 复制构造(拷贝构造)函数 目的是为了准确统计字符串个数,并且实现深拷贝,避免多次释放
    MyStrings(const MyStrings & str0);
    ~MyStrings();
    int length() const{return len;}
    // 赋值运算符重载,目的是为了实现深拷贝,避免多次释放
    MyStrings &operator=(const MyStrings& str0);
    MyStrings &operator=(const char *pChar);
    friend bool operator<(const MyStrings& str1,const MyStrings& str2);
    friend bool operator>(const MyStrings& str1,const MyStrings& str2);
    friend bool operator==(const MyStrings& str1,const MyStrings& str2);
    friend std::ostream& operator<<(std::ostream& os,const MyStrings& str0);
    char &operator[](int i);
    const char &operator[](int i)const ;
    static int HowMany();
private:
    int len;
    char *pStr;
    static int sNumString;
};


#endif //SEARCH_MYSTRINGS_H
