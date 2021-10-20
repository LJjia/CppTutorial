/**
 * @File: MyQueue
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 09:59 2021-10-19.
 * @Modify:
 */
#include <cstring>
#include <iostream>
#include "MyQueue.h"

using namespace std;

// const int MyQueue::const_tmp=10;
 int MyQueue::s_var=10;
/*!
 * 使用成员初始化列表来初始化const 或者引用变量
 * 构造函数的初始化会将原先的初始化覆盖
 * @param size
 */
MyQueue::MyQueue(int size) :qsize(size) {
    sNodeNum=0;
    pFront= nullptr;
    pRear= nullptr;
}

MyQueue::~MyQueue() {
    Node* pTmp;
    while(pFront){
        pTmp=pFront;
        delete pTmp;
        pFront=pFront->pNext;

    }
}

bool MyQueue::EnQueue(const Item &item) {
    Node *pNew= nullptr;
    if(isfull()){
        cout<<"queue full"<<endl;
        return false;
    }
    if(!pRear&&!pFront){
        pNew=new Node;
        memset(pNew,0,sizeof(Node));
        pFront=pRear=pNew;
        pNew->data=item;
        sNodeNum++;
        return true;
    } else if (pRear&&pFront){
        pNew=new Node;
        memset(pNew,0,sizeof(Node));
        pRear->pNext=pNew;
        pNew->data=item;
        sNodeNum++;
        return true;
    } else{
        cout<<"Maybe somethings err "<<pRear<<" "<<pFront<<endl;
        return false;
    }

}

bool MyQueue::DeQueue(Item &item) {
    Node *pTmp;
    if(pFront){
        item=pFront->data;
        pTmp=pFront;
        pFront=pFront->pNext;
        delete pTmp;
        sNodeNum--;
        return true;
    }else{
        cout << "queue count "<<sNodeNum<<endl;
        return false;
    }
}

void TestMyQueue(){
    MyQueue::HowMany();
//    MyQueue q;
//    q.EnQueue(10);
//    q.EnQueue(20);
//    q.EnQueue(30);
//    cout<<"queue size "<<q.Count()<<endl;
//    MyQueue q2;

}

void MyQueue::HowMany() {
    cout<<"echo money "<<money<<endl;
}

/*!
 * 送入队列时,随机摇设置用户处理时间,并记录送入队列时此时的时间
 * @param when
 */
void Customer::set(int when) {
    // 处理时间范围1-3
    processtime=rand()%3+1;
    cout<<"proc time "<<processtime<<endl;
    arrive=when;
}

void TestSimulateAtm(){

}

