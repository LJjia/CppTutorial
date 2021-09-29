/**
 * @File: stock
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 16:32 2021-09-17.
 * @Modify:
 */

#include <iostream>

#ifndef OBJECTANDCLASS_STOCK_H
#define OBJECTANDCLASS_STOCK_H


class Stock {
    enum class days:int{Monday,TuesDay,};
public:

    Stock(){
        std::cout<<"call no param func"<<" p "<<price<<std::endl;
    }

    Stock(int d,int de=5){
        data=d;
        std::cout<<"call param func "<<data<<" p "<<price<<" default "<<de<<std::endl;
    }

    ~Stock(){
        std::cout<<"bye"<<std::endl;
    }


    int price;
    int PtPirce() const {
        std::cout<<"price "<<price<<std::endl;
        return 0;
    }

private:


    int data;
};

class Stock1_1{
    static int x;
    int y;
};

#endif //OBJECTANDCLASS_STOCK_H
