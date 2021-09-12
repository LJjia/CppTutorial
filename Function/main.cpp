#include <iostream>
#include "run_func.h"
#include "new_features.h"
#include <stdio.h>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    TestFuncParam();
    TestNewFeature();
    TestDefaultParam();
    TestOverload();
    TestTemplate();
    cout<<"cin str"<<endl;
    char sz[20]{};
    cin.get(sz,20);
    cout<<sz<<" disp "<<cin.fail()<<endl;
    cin.get(sz,20);
    cout<<sz<<" disp"<<endl;
    return 0;
}