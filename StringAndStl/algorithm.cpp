/**
 * @File: algorithm
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 16:01 2021-11-07.
 * @Modify:
 */


#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <functional>
using namespace std;
using std::cout;
using std::endl;


char charLower(char ch){
    return tolower(ch);
}

string & ToLower(string & s0){
    transform(s0.begin(),s0.end(),s0.begin(),charLower);
    return s0;
}

void TestStaticString(){
    vector<string> v0{"Hello","nice","NICE","good","morning","heLLo","123","123","567","hello"};
    // 显示输入内容矢量
    cout<<"disp input vector"<<endl;
    for(auto & _i:v0){
        cout<<_i<<" ";
    }
    cout<<endl;
    // 显示包含单词列表的集合
    set<string> s1;
    transform(v0.begin(),v0.end(),insert_iterator<set<string>>(s1,s1.begin()),ToLower);
    cout<<"disp set content"<<endl;
    for(auto & _i:s1){
        cout<<_i<<" ";
    }
    cout<<endl;
    map<string,int> m1;
    for(set<string>::iterator iter=s1.begin();iter!=s1.end();iter++){
        m1[*iter]=count(v0.begin(),v0.end(),*iter);
    }

//    for(auto & iter:s1){
//        m1[iter]=count(v0.begin(),v0.end(),iter);
//    }

    cout<<"disp map content"<<endl;
    for(auto & _i:s1){
        cout<<_i<<":"<<m1[_i]<<" "<<endl;
    }
    cout<<endl;



}
