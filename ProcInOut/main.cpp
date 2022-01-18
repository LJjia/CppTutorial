#include <iostream>


void SimpleTestCout();
void TestCin();
void TestOpenFile();
void ProcFilePoint();
void  TestNoVirSave();
void  TestVirSave();

int main() {
    std::cout << "Hello, World!" << std::endl;
//    SimpleTestCout();
//    TestCin();
//    TestOpenFile();
//    ProcFilePoint();
    TestNoVirSave();
//    TestVirSave();
    for(char i:"helloworld"){
        std::cout<<i<<" ";
    }
    return 0;
}