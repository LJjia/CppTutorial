/**
 * @File: SimpleTest
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 10:44 2021-11-10.
 * @Modify:
 */
#include <iomanip>
#include "SimpleTest.h"

void SimpleTestCout(){
    int a=255;
    cout<<"simple Test "<<endl;
    cout<<"a "<<a<<endl;
    cout<<hex;
    cout<<"a "<<a<<endl;
    cout<<oct;
    cout<<"a "<<a<<endl;
    cout<<dec;
    cout<<"a "<<a<<endl;
    cout.width(10);
    cout<<"#"<<endl;
    cout.setf(ios_base::showpoint);
    cout<<2.0f<<endl;
    cout<<"set pre"<<cout.precision(4)<<endl;

    cout<<20.1234567<<endl;
    cout<<20.1<<endl;
    cout<<20.12<<endl;
    cout<<20122.3<<endl;
    cout<<201223.0f<<endl;
    cout.precision(6);

    cout.precision(6);
    cout<<"show point"<<endl;
    cout<<24.0<<endl;

    cout.unsetf(0xffff);
    cout<<"set default setting"<<endl;
    cout<<setw(14)<<"1:"<<"name"<<endl;
    cout<<setw(14)<<setfill('.')<<"2:"<<"region"<<endl;
    char ch=0;
    cin.get(ch);
    int cnt=0;
    while(ch!='\n'){
        cout<<ch;
        cin>>ch;
        cnt++;
    }
    cout<<endl<<"total "<<cnt<<endl;
}

#include <string>
void TestCin(){
//    char data[20]{"123"};
//    char data2[20]{};

//    cin.getline(data2,20);
//    cout<<"data "<<data[0]<<data[1]<<data[2]<<"-"<<data2;
    char ch;
    cout<<"input**"<<endl;
    while((ch=cin.peek())!='#'){
        cout<<"--"<<ch<<"--";
        cin.get(ch);
        cout<<"&&&"<<ch<<"&&&";
    }
}