/**
 * @File: tv
 * @Author: Jialiangjun
 * @Description: 有关电视机和遥控器的友元类
 * @Date: Created on 10:52 2021-10-30.
 * @Modify:
 */
#ifndef FRIENDSEXCEPTION_TV_H
#define FRIENDSEXCEPTION_TV_H

#include <iostream>
using std::cout;
using std::endl;

class Tv;
class Remote{
private:
    int mode;
public:
    enum {TV,DVD};
    explicit Remote(int m=TV);
    void volup(Tv & t);
    void voldown(Tv & t);
    void OnOff(Tv & t);
    void ChangeInput(Tv & t);
    void setChannel(Tv & t,int target);
};

class Tv {
public:
    friend void Remote::setChannel(Tv & t,int target);
    enum {On,Off};
    enum {TV,DVD};
    enum {MinVol=0,MaxVol=100};
    Tv(const char * n="UnNameTv",int s=Off):name(n),volume(0),input(TV),state(s),channel(0){};

    bool ison() const{return state==On;}
    // 异或1表示翻转,异或0表示不变
    void OnOff() {state^=1;};
    void volup();
    void voldown();
    void setinput(){input=(input=TV)?TV:DVD;}

    // 显示所有设置
    void setting() const;

private:
    std::string name;
    int volume;
    int input;// 电视输入类型 dvd tv
    int state; // is on off 表示电视开关
    int channel;
};


#endif //FRIENDSEXCEPTION_TV_H
