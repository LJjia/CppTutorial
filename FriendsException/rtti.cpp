/**
 * @File: rtti
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 17:10 2021-11-02.
 * @Modify:
 */
#include "rtti.h"
#include <typeinfo>

void TestRTTI(){
    A objA(" A ");
    B objB(" B ");
    C objC(" C ");
    A*pA=&objA;
    B*pB=&objB;
    C*pC=&objC;
#if 0
    pC=dynamic_cast<C*>(pA);
    pA=dynamic_cast<A*>(pB);
    cout<<"disp a addr a "<<pA<<endl;
    cout<<"disp a addr b "<<pB<<endl;
    cout<<"disp a addr c "<<pC<<endl;

    A&ra=objA;
    B&rb=objB;
    C&rc=objC;
    rc=(C&)ra;
    try {
        rc= dynamic_cast<C&>(ra);
    }catch(std::bad_cast & bad) {
        cout<<"catch bad cast"<<bad.what()<<endl;
    }
#endif
    cout<<"typeinfo "<< typeid(typeid(A)).name()<<endl;
    cout<<"typeinfo "<< typeid(A).name()<<endl;
    cout<<"typeinfo "<< typeid(B).name()<<endl;
    cout<<"typeinfo "<< typeid(*pA).name()<<endl;
    cout<<"typeinfo "<< typeid(pA).name()<<endl;
    cout<<"typeinfo "<< typeid(pB).name()<<endl;
    cout <<"equal A==B "<< (typeid(A)== typeid(B))<<endl;
    cout <<"equal B==A "<< (typeid(B)== typeid(A))<<endl;
    cout <<"equal A==A "<< (typeid(A)== typeid(A))<<endl;
    A*pTmp=pB;
    cout <<"equal *pA==*pB "<< (typeid(*pA)== typeid(*pTmp))<<endl;
    cout<<"typeinfo "<< typeid(*pA).name()<<endl;
    cout<<"typeinfo "<< typeid(*pTmp).name()<<endl;
    cout <<"equal *pA==*pA "<< (typeid(*pA)== typeid(*pA))<<endl;
    cout <<"equal *pA==A "<< (typeid(*pA)== typeid(A))<<endl;

}

void func(const int *pInt){
    int *pChg{};
    pChg= const_cast<int *>(pInt);
    *pChg+=1;
}

void funcOri(const int *pInt){
    int *pChg{};
    pChg= (int *)pInt;
    *pChg+=1;
}

void TestConstCast(){
    cout<<"Test const Cast"<<endl;
    const int ca=2000;
    func(&ca);
    funcOri(&ca);

    cout<<"const "<<ca<<endl;


    int cb=2000;
    int *pA=(int*)&cb;
    cout<<"addr pa "<<pA<<endl;
    *pA++;
    cout<<"addr pa "<<pA<<endl;

    func(&cb);
    cout<<"no const "<<cb<<endl;
}