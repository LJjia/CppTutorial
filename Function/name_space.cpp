/**
 * @Author: Jialiangjun
 * @Description:测试名称空间使用源文件
 * @Date: Created on 15:05 2021-09-14.
 * @Modify:
 */
#include <iostream>
#include "name_space.h"

namespace person
{
    using std::cout;
    using std::cin;
    using std::endl;

    void PtPersonality(){
        cout<<"test person namespace"<<20<<endl;
    }
}