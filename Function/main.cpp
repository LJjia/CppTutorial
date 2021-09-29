#include <iostream>
#include "run_func.h"
#include "new_features.h"
#include <stdio.h>

using namespace std;

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
    TestFuncParam();
    TestNewFeature();
    TestDefaultParam();
    TestOverload();
    TestTemplate();
    cout<<"hello world +++"<<endl;
    TestCin();
    return 0;
}


