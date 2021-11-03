/**
 * @File: QueueTp
 * @Author: Jialiangjun
 * @Description: queue的模板,其中使用嵌套类Noode
 * @Date: Created on 15:38 2021-10-30.
 * @Modify:
 */
#ifndef FRIENDSEXCEPTION_QUEUETP_H
#define FRIENDSEXCEPTION_QUEUETP_H


#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class QueueTp {
private:
    class Node{
    private:

    public:
        T items;
        Node *pNext;
        explicit Node(T val=0):items(val),pNext(nullptr){};
//        explicit Node(const T & val):items(val),pNext(nullptr){};
    };
    Node* pFront;
    Node* pRear;
    int sNodeNum;
    const int maxlen;
public:
    enum{MAX_LEN=10};
    explicit QueueTp(int len=MAX_LEN):pFront(nullptr),pRear(nullptr),sNodeNum(0),maxlen(len){};
    bool pop( T &t);
    bool push(const T & t);
    bool full(){return sNodeNum==maxlen;};
    bool empty(){return sNodeNum==0;};


};


#endif //FRIENDSEXCEPTION_QUEUETP_H
