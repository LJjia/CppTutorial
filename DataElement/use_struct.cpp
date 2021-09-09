/**
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 14:48 2021-08-19.
 * @Modify:
 */
#include "use_struct.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
struct Members{
    char name[40];
    // 只要编译器允许,就可以在结构体中定义string类型对象
    std::string desc;
    int age;
};

// 这样是定义了一个全局变量
struct Position{
   int x;
   int y;
}g_loc1;

// 这个结构体虽然只用了9位,仅超过1byte,但是sizeof大小还是4,感觉就像是最小大小就是4
// 设置成8位大小也是4
struct Regeister{
    unsigned int SN:4;
    unsigned int :4; //4bit未使用
    unsigned int b:1;
};

// 共用体,主要看如何调用成员的 调用为s.price.upirce
// _price_为共用体名字,price才为成员名  _price_共用体仅在结构体内部生效,不影响外部
struct Widget{
    char name[20];
    union _price_{
        int uprice;
        char szprice;
    }price;
};

union _price_{
    int price;
};

// 当然共用体也可以指定不写名字的,不指定名字的时候要用这种类似未命名共用体的定义,同时不指定成员变量名
// 那么调用就变成了 s.upirce
struct Widget2{
    char name[20];
    union {
        int uprice;
        char szprice;
    };
};

// 枚举 默认数据类型为整形
enum Week{
    Sunday=0,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
};
enum Color{
    Red,
    Blue,
    Yellow,
    Pink,
};

void TestSruct(){
    Members jack {
            "Jack",
            "handsome",
            20,
    };

    Members anny{};
    Members nobody{};
    strcpy(anny.name,"Anny");
    anny.desc="female beautiful";
//    anny.name="unknow";
    anny.age=22;
    cout<<jack.name<<" "<<jack.desc<<" "<<jack.age<<endl;
    cout<<anny.name<<" "<<anny.desc<<" "<<anny.age<<endl;
    // 结构体元素相互复制,很简单
    nobody=jack;
    cout<<nobody.name<<" "<<nobody.desc<<" "<<nobody.age<<endl;
    g_loc1.x=g_loc1.y=100;
    cout<<"position "<< g_loc1.x << " "<<g_loc1.y<<endl;
    // 结构体数组初始化,未被初始化的元素将自动赋值为0
    Position LocList[4] {{1,2},{3,4}};
    cout <<"Pt LocList"<<endl;
    for(int i;i<4;i++){
        cout<<LocList[i].x<<" "<<LocList[i].y<<endl;
    }
    Regeister reg{};
    reg.SN=12;
    // 越界部分会自动取补码 ,以下部分会报warning 暂时注释
//    reg.b=3;
    reg.b=1;
    cout<<"reg size "<< sizeof(reg) << " "<< reg.b<<" "<<reg.SN<<endl;
    // 主要看一下共用体的调用方法
    Widget items1{};
    Widget2 items2{};
    items1.price.uprice=9;
    items2.uprice=0;

    Week day1;
    Week day2;
    day1=Saturday;
    day2=Tuesday;
    int total;
    // 枚举类型进行运算会强制转化为整形的运算
    total=day1+day2;
    // 枚举也是一个类型,可以用作强制类型转换 两种方法
    // 如果强转了一个不是枚举的值,但只要在int的取值范围内,语句也是合法的
    day1=Week(5);
    day1=(Week)5;
    // 枚举类型只有复制操作,并且枚举类型只能接受当前枚举类型的赋值,不可将int复制给枚举类型变量
//    day1=5;
//    day1=Yellow;
    cout<<"Pt enum type "<<day1<<" "<<day2<<" "<< total<<" "<< sizeof(day1)<<endl;

    int num=0;
    int *p=&num;
    cout<<"pt point addr "<< p<< endl;
}