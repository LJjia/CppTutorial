/**
 * @File: MyQueue
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 09:59 2021-10-19.
 * @Modify:
 */
#ifndef OBJECTANDCLASS_MYQUEUE_H
#define OBJECTANDCLASS_MYQUEUE_H


class Customer{
private:
    int arrive;
    int processtime;
public:
    Customer(){arrive=processtime=0;};
    // 计数器递增,用户送入队列时,记录送入的时间when
    void set(int when);
    int when(){return arrive;}
    int howlong(){return processtime;}
};

typedef int Item;

class MyQueue {
private:


    enum {
        Q_SIZE=10,
    };

    struct Node{
        Item data;
        Node*pNext;
    };

    // 如果直接赋值,等价于在构造函数中使用成员初始化列表
    Node*pFront= nullptr;
    Node*pRear;
    int sNodeNum;
    const int qsize;
    static const int const_tmp=20;
    static int s_var;
    // 将复制构造函数和赋值运算符定义为私有类型,因此外部无法调用这两个函数
    // 避免对象复制出现问题
    MyQueue(const MyQueue& q):qsize(0){}
    MyQueue&operator=(MyQueue& q){return *this;};

public:
    explicit MyQueue(int size=Q_SIZE);
    ~MyQueue();
    // 出队
    bool DeQueue(Item &item);
    // 入队
    // 如果这里的Item是一个对象,那么传入非const类型会不会调用拷贝构造创建一个对象?
    bool EnQueue(const Item &item);
    int Count(){ return sNodeNum;}
    bool isfull(){return sNodeNum>=qsize;}
    bool isempty(){return sNodeNum<qsize;}
    static void HowMany();
    static const int money=10;



};


#endif //OBJECTANDCLASS_MYQUEUE_H
