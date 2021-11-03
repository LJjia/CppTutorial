#include <iostream>
void TesTvRemote();
void TestQueueTp();
void call_abort();
void try_except();
void TesThrow1();
void TestRTTI();
void TestConstCast();


#include "error_class.h"
#include <exception>
using namespace std;
void MyQuit(){
    cout<<"MyQuit program"<<endl;
    exit(6);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
//    TesTvRemote();
//    TestQueueTp();

//    call_abort();
//    try_except();

//    TesThrow1();
//    TestRTTI();
    TestConstCast();
    std::cout<<"------------run end----------"<<std::endl;

    return 0;
}