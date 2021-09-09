#include <iostream>
#include "run_func.h"
#include "new_features.h"
#include <stdio.h>

int testfunc(const int x){

    return x*x;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    TestFuncParam();
    TestNewFeature();
    auto tmp="pizza"[2];
    std::cout<<"test const "<<tmp<<std::endl;
    return 0;
}