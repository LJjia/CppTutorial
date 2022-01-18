/**
 * @File: program
 * @Author: Jialiangjun
 * @Description: 编程练习
 * @Date: Created on 09:46 2021-11-09.
 * @Modify:
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <numeric>
#include <list>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;

/*!
 * 清楚字符串中的标点符号,空格等,只留下字母,并且全部转化为小写
 * @param s
 * @return
 */
string clean(const string & s){
    string out;
    for(auto ch=s.begin();ch!=s.end();ch++){
        if(isalpha(*ch)){
            out.push_back(tolower(*ch));
        }else{
            // 舍弃
        }
    }
    return out;
}

/*!
 * 判断是否为回文
 * @param s
 * @return
 */
bool bPalindrome(const string & s){
    string cleaned=clean(s);

    string reversed;
    for(auto ch=cleaned.rbegin();ch!=cleaned.rend();ch++){
        reversed.push_back(*ch);
    }
    return cleaned==reversed;
};

void TestPalindromeStr(){
    string data[]={"Adam","Madam ,I'm Adam","Otto","AOA","bb"};
    for (auto & s:data){
        cout<<s<<" : "<<bPalindrome(s)<<endl;
    }
}

/*!
 * 删除数组中重复的值,不一定要相邻元素
 * @param ar
 * @param n
 * @return
 */
int DeleteSame(int *ar,int n){
    int *addr= nullptr;
    int cnt=0;
    std::sort(ar,ar+n);
    addr=std::unique(ar,ar+n);
    for(;ar!=addr;ar++,cnt++);

    return cnt;
    // 也可以直接返回相减,但是可能涉及截断的问题
    return addr-ar;
}


void TestDelSameValue(){
    int aInt[]={10,20,10,20,30,30,30,40,50};
    int len=0;
    len=DeleteSame(aInt, sizeof(aInt)/sizeof(int));
    for(int i=0;i<len;i++){
        cout<<aInt[i]<<" ";
    }
    cout<<endl;
}

const vector<int> shuffle(int len,int num){
    vector<int> v0(len);
    iota(v0.begin(),v0.end(),0);
    random_shuffle(v0.begin(),v0.end());
//    vector<int> ret(v0.begin(),v0.begin()+num);
    vector<int> ret(num);
    std::copy(v0.begin(),v0.begin()+num,ret.begin());
    return ret;
}

void TestShuffle(){
    vector<int> winner;
    for(auto i:{2,2,3}){
        winner=shuffle(50,i*2);
        for(auto j:winner){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

#include <ctime>


 unsigned long ListSort(list<int>& l){
    clock_t t0=clock();
    l.sort();
    return clock()-t0;

}

unsigned long  VectorSort(vector<int> &v){
    clock_t t0=clock();
    std::sort(v.begin(),v.end());
    return clock()-t0;
}

unsigned long  UseCpy(vector<int> &v,list<int>& l){
    clock_t t0=clock();
    std::copy(l.begin(),l.end(),v.begin());
    std::sort(v.begin(),v.end());
    std::copy(v.begin(),v.end(),l.begin());
    return clock()-t0;
}

void TestSort(){
    list<int> list1(1000);
    vector<int> vector1(1000);
    for(auto &_i : list1){
        _i=rand()%100;
    }
    for(auto &_i : vector1){
        _i=rand()%100;
    }
    cout<<"-----------"<<endl;
//    cout<<"list sort "<<ListSort(list1)<<endl;
//    cout<<"vector sort "<<VectorSort(vector1)<<endl;
//    cout<<"copy sort "<<UseCpy(vector1,list1)<<endl;
}

