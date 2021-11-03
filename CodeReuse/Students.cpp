/**
 * @File: Students
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 16:50 2021-10-22.
 * @Modify:
 */
#include "Students.h"


const string& Kids::Name() {
    return Students::name;
}

void TestSudents(){
    Kids kid;
    cout<<"kid name "<<kid.Name()<<endl;
    kid.run(1,2);
    kid.run(1);
}
