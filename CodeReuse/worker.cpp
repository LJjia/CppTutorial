/**
 * @File: worker
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 11:29 2021-10-24.
 * @Modify:
 */
#include "worker.h"

void Worker::set() {
    cout<<"set worker name "<<endl;
    FullName="workers";
}

void Worker::show() const {
    cout << "worker name "<<FullName<<" id "<<id<<endl;
}

Worker::~Worker()=default;

//int Worker::purevir() {return 0;};

void Waiter::set() {
    cout<<"set waiter ";
    Worker::set();
}

void Waiter::show() const {
    cout <<"waiter show pan "<<panache<<" ";
    Worker::show();
}

void Singer::show() const {
    cout <<"Signer show voice "<<voice<<" ";
    Worker::show();
}

void Singer::set() {
    cout<<"set Singer ";
    Worker::set();
}

void TestWorker(){
    Waiter wt;


}

void SingerWaiter::call() {
    show();
    Singer::show();
    Waiter::show();
}

void SingerWaiter::show() const {
    cout <<"singer waiter show"<<endl;
    Singer::show();
    Waiter::show();
}

void SingerWaiter::set() {
    cout<<"set SingerWorker ";
    Singer::set();
    Waiter::set();
}


