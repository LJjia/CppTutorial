/**
 * @File: storageclass
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 09:23 2021-11-12.
 * @Modify:
 */
#include "storageclass.h"

#include <fstream>
using namespace std;


void  TestNoVirSave(){
    SaveClassNoVirSon son("Son",12,1,140);
    ofstream fout("NoVirSon.bin",ios::out|ios::binary);
    cout<<"-------------------write to file"<<endl;
    son.disp();
    cout<<"sizeof son "<<sizeof(son)<<endl;
    fout.write((char*)&son,sizeof(son));
    fout.close();

    SaveClassNoVirSon tmp;
    cout<<"-------------------restore from file"<<endl;
    ifstream fin("NoVirSon.bin",ios::in|ios::binary);
    fin.read((char*)&tmp, sizeof(tmp));
    tmp.disp();
    fin.close();
}



void  TestVirSave(){
    SaveClassVirSon son("Son",12,1,140);
    ofstream fout("VirSon.bin",ios::out|ios::binary);
    cout<<"-------------------write to file"<<endl;
    son.show();
    cout<<"sizeof son "<<sizeof(son)<<endl;
    fout.write((char*)&son,sizeof(son));
    fout.close();

    SaveClassVirSon tmp;
    cout<<"-------------------restore from file"<<endl;
    ifstream fin("VirSon.bin",ios::in|ios::binary);
    fin.read((char*)&tmp, sizeof(tmp));
    tmp.show();
    fin.close();
}