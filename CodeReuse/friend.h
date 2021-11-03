/**
 * @File: friend
 * @Author: Jialiangjun
 * @Description: 类模板的友元函数
 * @Date: Created on 17:09 2021-10-27.
 * @Modify:
 */
#ifndef CODEREUSE_FRIEND_H
#define CODEREUSE_FRIEND_H


#include <iostream>

using std::cout;
using std::endl;
template <typename T> class HasFriend;
template <typename T> void counts();
template <typename T> void formalparam(T in);
template <typename T> void reports(HasFriend<T> &hf);


template<typename T>
class HasFriend {
private:
    T items;
    static int ct;
public:
    explicit HasFriend(const T &i) : items(i) { ct++; };

    ~HasFriend() { ct--; }

    friend void counts<T>();

    friend void formalparam<>(T in);

    friend void reports<>(HasFriend<T> &hf);
    template <typename C>friend void allin(C c);
};


#endif //CODEREUSE_FRIEND_H
