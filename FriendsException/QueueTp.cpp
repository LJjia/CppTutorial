/**
 * @File: QueueTp
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 15:38 2021-10-30.
 * @Modify:
 */
#include "QueueTp.h"


template <typename T>
bool QueueTp<T>::pop( T &t) {
    Node *pNode=pFront;
    if(sNodeNum<=0){
        return false;
    }
    pFront=pFront->pNext;
    t=pNode->items;
    delete pNode;
    sNodeNum--;
    if(sNodeNum==0){
        pFront=pRear= nullptr;
    }
    return true;
}

template <typename T>
bool QueueTp<T>::push(const T &t) {
    Node*pNew= nullptr;
    if(sNodeNum==maxlen){
        return false;
    }
    pNew=new Node(t);
    if(sNodeNum==0){
        pFront=pRear=pNew;
    } else{
        pRear->pNext=pNew;
        pRear=pNew;
    }
    sNodeNum++;
    return true;

}


void TestQueueTp(){
    QueueTp<int> q1;
    int ret=0;
    q1.push(10);
    q1.push(20);
    q1.pop(ret);
    cout<<"first pop "<<ret<<endl;
    q1.push(30);
    q1.pop(ret);
    cout<<"sec pop "<<ret<<endl;
    q1.pop(ret);
    cout<<"third pop "<<ret<<endl;


}

