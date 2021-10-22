/**
 * @File: fruits
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 14:40 2021-10-20.
 * @Modify:
 */
#include <iostream>
#include "fruits.h"

using namespace std;





Fruits::Fruits(const std::string &n, int kj,int w) {
    cout<<"fruit construct "<<endl;
    name=n;
    caloris=kj;
    weight=w;
}

Fruits::~Fruits() {
    std::cout<<"fruit destroy"<<std::endl;

}

int Fruits::kg() {
    return weight;
}

int Fruits::Usage() {
    cout<<"fruits usage"<<endl;
    return 0;
}

void Fruits::SameName(int x) {
    cout<<"same name "<<x<<endl;
}

void Fruits::SameName(int x,int y) {
    cout<<"same name "<<x<<y<<endl;
}

Apple::Apple(const std::string &n, int kj, int w, int c):Fruits(n,kj,w) {
    cout<<"apple construct"<<endl;
    color=c;
}

Apple::Apple(const Fruits &f, int c) :Fruits(f){
    color=c;
}

void Apple::SameName(int x) {
    cout<<"same name "<<x<<endl;
}

void Apple::SameName(int x,int y) {
    cout<<"same name "<<x<<y<<endl;
}

int Apple::Usage() {
    this->Fruits::Usage();
    cout<<"Apple eat it! "<<endl;
    return 0;
}

void AppleTree::TestPt() {
    ProtectWay();
}

/*!
 * 父类中纯虚函数的外部定义,尽管父类中实际有纯虚函数的定义,
 * 但是子类仍要自己重新定义所有的纯虚函数,否则子类就是抽象类,不可创建实体
 * @return
 */
int BaseShape::Area() const {
    cout<<"calc area"<<endl;
    return 0;
}


void TestFruits(){
    Fruits* pA1=new Apple("apple",100,1,C_RED);
    pA1->Usage();
    pA1->SameName(10);
    Apple* pA2=(Apple*)pA1;
    pA2->SameName(10,20);
    delete pA1;
    AppleTree tree;
    tree.TestPt();
    cout<<"******dividing line*******"<<endl;
    Circle cir;
    Circle cir2;
    cir.Hide();
    BaseShape *pBaseShape=&cir;
    pBaseShape->operator=(cir);
    cir2=cir;
//    cir.Hide(1,2);

}
