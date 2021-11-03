/**
 * @File: err_proc
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 16:28 2021-10-30.
 * @Modify:
 */

#include <iostream>
#include <cstdlib>
#include "error_class.h"


using std::cout;
using std::endl;

void call_abort(){
    cout<<"call abort"<<endl;
    abort();
}


void throwClass(){
   cout<<"enter throw 1"<<endl;
   throw BadMessage1(1);
}

void throwChar(){
    cout<<"enter throw 1"<<endl;
    throw "This is an error !";
}

void throwInt(){
    cout<<"enter throw 1"<<endl;
    throw 20;
}

void throwClassLayer(){
    Chatter chat("chat ");
    throwChar();
}

void throwMess2(){

    throw BadMessage2(10);
}

void TesThrow1(){

    try {
//        throwClass();
//        throwChar();
//        throwInt();
//        throwClassLayer();
        throwMess2();
//    }catch (BadMessage2& bad){
//        bad.Message();
    }catch (BadMessage1& bad){
        bad.Message();
    }
    catch (const char * s){
        cout <<"catch const char "<<s<<endl;

    }
    cout<<"continue run end"<<endl;
}

void try_except(){
    cout<<"call try"<<endl;
    try{
        char * p = nullptr;
        if(p[0]);
        cout <<"divide end"<<endl;
        throw "divide zero";
    }catch (const char *s ){
        cout<<s<<" error"<<endl;

    };
}
