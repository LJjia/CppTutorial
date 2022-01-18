#include <iostream>
using std::cout;
using std::endl;


void TestrightRef();
void TestAdapt();
void TestParamList();
void TestSum();
void TestRightValueParam();


int main() {
    std::cout << "Hello, World!" << std::endl;
//    TestrightRef();
//    TestAdapt();
//    TestParamList();
//    TestSum();
    TestRightValueParam();
    int a=0;
    int *p=&a;
    ++*p;
    cout <<"a "<<a<<endl;
    return 0;
}