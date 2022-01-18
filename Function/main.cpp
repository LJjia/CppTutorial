#include <iostream>
#include "run_func.h"
#include "new_features.h"
#include <stdio.h>

using namespace std;

void TestInOut();

void TestCin(){
    string InputStr;
    cout<<"Input something"<<endl;
    getline(cin,InputStr);
    if(InputStr==""){
        cout<<"input empty"<<endl;
    } else{
        cout<<"input "<<endl;
    }
    cout << "cin "<<cin.fail()<<endl;

}

int main() {

    std::cout << "Hello, World!" << std::endl;
//    TestFuncParam();
//    TestNewFeature();
//    TestDefaultParam();
//    TestOverload();
//    TestTemplate();
//    cout<<"hello world +++"<<endl;
//    TestCin();
    TestInOut();
    int a[10]{1,2,3,4,5};
    void* p=a;
    int *pInt=a;
    p=pInt;
    cout<<"hello "<<endl<<flush;
    std::endl(cout);
    std::flush(cout);
    return 0;
}


