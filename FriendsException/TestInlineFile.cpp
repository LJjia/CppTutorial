/**
 * @File: TestInlineFile
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 14:26 2021-10-30.
 * @Modify:
 */

#if 1
#include "tv.h"

void TesTvRemoteExternFunc(){
    Tv tv1("tv1",Tv::On);
    Tv tv2("tv2",Tv::On);
    Remote r1;
    tv1.setting();
    r1.volup(tv1);
    r1.OnOff(tv1);
    cout << " ---Remote close tv ---"<<endl;
    tv1.setting();
    r1.volup(tv2);
    r1.setChannel(tv1,20);
};
#endif
