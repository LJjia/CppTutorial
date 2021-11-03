/**
 * @File: tv
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 10:52 2021-10-30.
 * @Modify:
 */
#include "tv.h"

void Tv::setting() const {
    if(state==Off){
        cout << name <<"tv not open "<<endl;
        return ;
    }
    cout<<"disp setting"<<endl;
    cout<<" vol "<<volume;
    cout<<" state "<<state;
    cout<<" input "<<input;
    cout<<" channel "<<channel;
    ;
    cout<<endl;
}

void Tv::voldown() {
    cout<<name<<" set vol down"<<endl;
    if(volume>MinVol){
        volume--;
    }

}

void Tv::volup() {
    cout<<name<<" set vol up"<<endl;
    if(volume<MaxVol){
        volume--;
    }

}

Remote::Remote(int m):mode(m){

}

inline void Remote::volup(Tv &t){
    t.volup();
}

void Remote::voldown(Tv &t) {
    t.voldown();
}

inline void Remote::OnOff(Tv & t){
    t.OnOff();
}

void Remote::ChangeInput(Tv & t){
    t.setinput();
}

void Remote::setChannel(Tv & t,int target){
    t.channel=target;
}

void TesTvRemote(){
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
