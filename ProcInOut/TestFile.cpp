/**
 * @File: TestFile
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 09:56 2021-11-11.
 * @Modify:
 */
#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <iomanip>

using namespace std;


class A{
private:
    int data;
public:
    explicit A(int d=0):data(d){}
    ~A()= default;
    operator bool() const {
        return data!=0;
    }
};


void TestOpenFile(){
    string name="content.txt";
    ofstream fout;
    fout.open(name);
    fout<<"helloworld\n2021.11.11"<<endl;
    fout.close();
    ifstream fin;
    fin.open(name.c_str());
    string line;
    cout<<"content file :"<<endl;
    while(getline(fin,line)){
        cout<<line<<endl;
    }
    int a,b;
    char szName[100]{"123"};
    cout <<"input :"<<endl;
    cin>>a;
    cin>>b;
    cin.get(szName,100);
    cout<<"disp "<< a <<" "<<b<<" "<<szName;

}

void ProcFilePoint(){
    string filename="content.txt";
    fstream finout;
    finout.open(filename,ios::in|ios::out|ios::binary);
    int ct=0;
    char ch=0;
    const char *p="Append!";
    int size=strlen(p);
    if(finout.is_open()){
        finout.seekg(0,ios_base::beg);
        finout.read(&ch,1);
        cout<<"get fir "<<ch<<endl;
        finout.read(&ch,1);
        cout<<"get sec "<<ch<<endl;
    }
    finout.seekg(3,ios_base::end);
    finout.read(&ch,1);
    finout.clear();
    cout<<"point pos "<<finout.tellg()<<endl;
//    finout.write(p,size);
    char tmpName[]{"tmp_XXXXX"};
    int fd;
    fd=mkstemp(tmpName);
    cout<<"generate tmp file name "<<tmpName<<"*"<<fd<<endl;

    close(fd);
    unlink(tmpName);
    cout<<hex<<showbase<<12<<endl;
    cout<<right<<setw(20)<<12<<endl;
    cout<<16;
}
