#include <vector>
#include <iostream>
/**
 * @File: use_vector
 * @Author: Jialiangjun
 * @Description: vector类的使用方法
 * @Date: Created on 11:43 2021-11-05.
 * @Modify:
 */


using std::cout;
using std::endl;

bool MyAscendingSort(int a,int b){
    return a<b;
//    if(a>b){
//        return false;
//    } else{
//        return true;
//    }

}

template <typename T>
void show(const T & ele){
    cout<<"ele "<<ele<<endl;
}
template void show<int>(const int & ele);


void TestVectorSort(){
    std::vector<int> v0{3,1,2,5,4};
    sort(v0.begin(),v0.end(),MyAscendingSort);
    for_each(v0.begin(),v0.end(),show<int>);
}
