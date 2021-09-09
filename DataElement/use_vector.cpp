/**
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 10:56 2021-08-21.
 * @Modify:
 */
#include "use_vector.h"
#include <vector>
#include <array>
#include <iostream>

using namespace std;

struct Pos {
    int x;
    int y;
};
struct Rect {
    int x, y, w, h;
};


void TestVector() {
    //初始化vector 是否需要销毁?  但是可以知道的是vector对象存在的内存空间不是栈,而是自由存储区或者堆中
    // 好处是元素个数可以使变量,并且可以一开始不对元素个数进行赋值(这样表示元素个数为空)
    // vector没有好的初始化方法
    vector<Pos> loc_list(2);
    loc_list[0].x = 10;
    loc_list[0].y = 20;
    loc_list[1].x = 10;
    loc_list[1].y = 20;
    // c++中 vector不会捕获-1这种问题 ,数组也不会,array也不会捕获这种问题
    // -1的作用 相当于 让指针-1然后取值 ,不是增加65536再取值的意思
//    loc_list[-1].y=20;
    for (int i = 0; i < 2; i++) {
        cout << "pt loc vector " << loc_list[i].x << " " << loc_list[i].y << endl;
    }
    // 初始化array 记住元素个数不可是变量
    // 内存存在于栈中
    array<Pos, 2> pos_list = {1, 2, 3, 4};
    array<Pos, 2> pos_list2;
    // size 相同的array可以直接赋值
    pos_list2 = pos_list;
    // array 也不会捕获-1这种错误的索引
    pos_list2[-1].x = 25;
    for (int i = 0; i < 2; i++) {
        cout << "pt loc array " << pos_list2[i].x << " " << pos_list2[i].y << endl;
    }

    array<string, 2> string_list = {"1234", "5678"};
    string_list[1] = "nice to meet";
    cout << "disp strings " << string_list[0] << "  " << string_list[1] << endl;


}
