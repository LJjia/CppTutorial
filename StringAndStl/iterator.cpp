/**
 * @File: iterator
 * @Author: Jialiangjun
 * @Description: 迭代器
 * @Date: Created on 15:41 2021-11-05.
 * @Modify:
 */
#include <vector>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <map>


using std::cout;
using std::endl;

#define show_list(element) for(auto _i:element){\
                                std::cout<<" "<<_i;\
                            }\
                            std::cout<<endl;\


void TestIterator(){
    double arr[]{1,2,3,4,5};
    std::vector<int> v1{1,2,3,4,5};
    std::vector<int> v2{1,2,3,4,5};

    cout<<"-------------"<<endl;
    std::vector<int>::iterator i1;
    std::vector<int>::iterator i2;
    i1=v1.begin()+1;
    i2=v2.begin()+1;
    cout<<"equal ?"<<(*i1==*i2)<<endl;
    for(auto i:arr){
        cout<<" "<<i<<endl;
    }
}

using namespace std;

void TestModel(){
    // 因为指针也是一种迭代器的具体实现,指针满足迭代器的所有要求
    // 所以也可以将stl算法用于基于指针的非stl容器
    int aInt[5]{0,3,2,1,4};
    std::vector<int> v1(8,0);
    std::sort(aInt,aInt+5);

    show_list(aInt);
    std::copy(aInt,aInt+5,v1.begin());
    show_list(v1);
//    std::ostream_iterator<int,char> out_iter(cout," ");
//    std::copy(v1.begin(),v1.end(),out_iter);
//    std::copy(aInt,aInt+5,out_iter);
//    cout<<endl;
    std::copy(aInt,aInt+5,v1.begin());
    for(auto iter=v1.rbegin();iter!=v1.rend();iter++){
        cout<<*iter<<" ";
    }

    cout<<endl;

    std::vector<int > v2{0,1,2,4,5};
    v2.reserve(20);
    cout<<"size "<<v2.capacity()<<endl;

    int aData[5]{1,2,3,4,5};
    std::vector<int> v3{1,2,3};
    std::back_insert_iterator<std::vector<int>> back_iter(v3);
    std::copy(aData,aData+5,back_iter);
    show_list(v3);

    std::list<int> v4(aData,aData+5);
    std::list<int> v5{7,8,9};
    v4.merge(v5);
    cout<<" merge "<<endl;
    show_list(v4);
    show_list(v5);
    v5.push_back(20);
    v5.push_back(30);
    v4.insert(v4.end(),v5.begin(),v5.end());
    cout<<" insert "<<endl;
    show_list(v4);
    show_list(v5);
    v4.splice(v4.begin(),v5);
    cout<<" splice "<<endl;
    show_list(v4);
    show_list(v5);
    v4.remove(20);
    cout<<" remove "<<endl;
    show_list(v4);

    std::set<std::string> s1{"a","b","c","d","e"};
    std::ostream_iterator<std::string,char> out(std::cout);
    std::copy(s1.lower_bound("b"),s1.upper_bound("d"),out);
    cout<<endl;

    multimap<int,string> codes;
    int a=0;
    codes.insert(pair<int,string>(a,"hefei"));
    codes.insert(pair<int,string>(0,"beijing"));
    codes.insert(pair<int,string>(1,"hangzhou"));
    pair<multimap< int,string>::iterator,multimap< int,string>::iterator> range=codes.equal_range(0);
    // equal_range返回的range是一个pair,first和seconde 分别表示有效数据开始的迭代器和结束的迭代器
    // 对这个迭代器解引用*,然后去fisrt和second将获得int类型和城市string名
    multimap< int ,string>::iterator it;
    for(it=range.first;it!=range.second;it++){
        cout<<" area code "<<(*it).first<<" city "<<(*it).second<<endl;
//        (*it).first++;
    }
    cout<<"-----------"<<endl;
    multimap<int,string>::iterator iterator1;
    for(iterator1=codes.begin();iterator1!=codes.end();++iterator1){
        cout<<"typeid "<< typeid(iterator1).name()<<endl;
        cout<<" area code "<<(*iterator1).first<<" city "<<(*iterator1).second<<endl;
    }

}

