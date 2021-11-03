/**
 * @File: stacktp
 * @Author: Jialiangjun
 * @Description: 栈的模板类声明
 * @Date: Created on 14:05 2021-10-26.
 * @Modify:
 */
#ifndef CODEREUSE_STACKTP_H
#define CODEREUSE_STACKTP_H


#include <iostream>

using std::cout;
using std::endl;

template<class Type>
class Stack {
private:
    enum {
        SIZE = 10
    };
    int stacksize;
    Type *pItems;
    int top;
public:
    Stack(int ss = SIZE);

    ~Stack();

    bool isempty();

    bool isfull();

    bool push(const Type &item);

    bool pop(Type &item);

    Stack<Type> &operator=(const Stack<Type> &s);

    void DispItems();

};


template<class Type>
Stack<Type>::Stack(int ss) {
    top = 0;
    stacksize = ss;
    pItems = new Type[ss];
}

template<class Type>
Stack<Type>::~Stack() {
    delete[]pItems;
}

template<class Type>
bool Stack<Type>::isempty() {
    return top == 0;
}

template<class Type>
bool Stack<Type>::isfull() {
    return top == stacksize;
}


template<class Type>
bool Stack<Type>::push(const Type &item) {
    if (isfull()) {
        cout << "stack is full push failed" << endl;
        return false;
    } else {
        pItems[top++] = item;
        return true;
    }
}

template<class Type>
bool Stack<Type>::pop(Type &item) {
    if (isempty()) {
        cout << "empty pop failed" << endl;
        return false;
    } else {
        item = pItems[--top];
        return true;
    }
}

template<class Type>
Stack<Type> &Stack<Type>::operator=(const Stack<Type> &s) {
    if (this == &s) {
        return *this;
    }
    delete[] pItems;
    pItems = new Type[s.stacksize];
    for (int i = 0; i < s.top; i++) {
        // 这种方式可以方便赋值运算符的重载
        pItems[i] = s.pItems[i];
    }
    stacksize = s.stacksize;
    top = s.top;
    return *this;
}

template<class Type>
void Stack<Type>::DispItems() {
    cout << "stack has " << stacksize << " size,items " << top << " Addr " << pItems << endl;
    for (int i = 0; i < top; i++) {
        cout << pItems[i] << " ";
    }
    cout << endl;
}

template<typename Type>
class One {
private:
    Type a;
public:
    One(Type n = 0) : a(n) {};

    Type &first() {
        cout << "call normal" << endl;
        return a;
    };

    Type &first() const {
        cout << "call const" << endl;
        return a;
    };
};





/*!
 * 类中添加模板类,模板函数定义
 * 有的编译器不支持在类中添加模板,下面给出在类中和类外定义的方式
 */

#if 0

template <typename T>
class beta{
private:
    template <typename V>
    class hold;
    hold<T> q;  // 这里表明根据类内模板创建q对象,hold类模板V对应外层beta类的T,传入具体的T,才会创建具体的模板类型
    hold<int > n;   // 这里表明根据类内模板创建n对象,hold类模板V对应int(已实例化声明)
public:
    beta(T t,int i):q(t),n(i){};
    template <typename U>
    U blab(U u,T t);    //函数模板 调用具体函数时,才会根据形参类型创建具体定义
    void Show() const{q.show();n.show();}
};


template <typename T>
    template <typename V>
    class beta<T>::hold{
    private:
        V val;
    public:
        explicit hold(V v=0):val(v){};
        void show(){cout<<"value "<<val<<endl;}
        V value(){return val;};
    };

template <typename T>
template <typename U>
U beta<T>::blab(U u,T t){
    cout<<"add value "<<(n.Value() + q.Value())<<endl;
    return (n.value()+q.value())*u/t;
}


#else

template<typename T>
class beta {
private:
    template<typename V>
    class hold {
    private:
        V val;
    public:
        explicit hold(V v = 0) : val(v) {};

        void show() const {cout<<"value "<<val<<endl;};

        V Value() const { return val; };
    };

    hold<T> q;
    hold<int> n;
public:
    beta(T t, int i) : q(t), n(i) {};

    template<typename U>
    U blab(U u, T t) {
        cout<<"add value "<<(n.Value() + q.Value())<<endl;
        return (n.Value() + q.Value()) * u / t;
    };

    void Show() {
        q.show();
        n.show();
    };
};


#endif


/*!
 * 模板类作为模板的参数
 */

template <template <typename T> class Thing>
        class Crab{
        private:
            Thing<int >s1;
            Thing<double>s2;
        public:
            Crab()= default;
            bool push(int a,double b){cout<<"crab push"<<endl;return s1.push(a)&&s2.push(b);}
            bool pop(int &a,double &b){cout<<"crab pop"<<endl;return s1.pop(a)&&s2.pop(b);}
        };

#endif //CODEREUSE_STACKTP_H
