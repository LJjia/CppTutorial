/**
 * @File: smartptr
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 14:57 2021-11-04.
 * @Modify:
 */
#include "smartptr.h"
#include <memory>

void TestSmartPtr(){
//    Report * pr=new Report("auto");
//    Report &rr=*pr;
    cout<<"---------Test Smart Ptr-----------"<<endl;
    {
        std::auto_ptr<Report> ps(new Report("using auto ptr"));
        ps->comment();
    }

    {
        std::unique_ptr<Report> ps(new Report("using unique ptr"));
        ps->comment();
    }

    {
        std::shared_ptr<Report> ps(new Report("using shared ptr"));
        ps->comment();
    }
}

void TestBelong(){
//    using ap=std::auto_ptr<string>;
    using ap=std::unique_ptr<string>;
    //using ap=std::shared_ptr<string>;
    ap film[3]{
        ap(new string("first")),
        ap(new string("second")),
        ap(new string("third")),
    };
    ap winer;
    winer=film[2];
    winer=std::move(film[2]);
    for(int i=0;i<3;i++){
        cout<<"film "<<*film[i]<<endl;
    }
    cout<<"winner "<<*winer<<endl;

}

std::unique_ptr<Report> RetPtr(){
    cout <<"enter retptr func"<<endl;
    std::unique_ptr<Report> sp(new Report("inner func"));
    return sp;
}

void InputPtr(std::shared_ptr<Report> ptr){
    cout <<"input ptr"<<endl;
}

void TestFuncRet(){
    cout<<"Test func ret"<<endl;
    Report*pReport= new Report("123");
    std::shared_ptr<Report> up(pReport);
    InputPtr(up);
    up->comment();
    cout<<"Test func ret end"<<endl;
}

