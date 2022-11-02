#pragma once
#include <string>
#include <iostream>
using namespace std;
#include<QString>
#include"user.h"
class user;
class good
{
public:
    friend class gamble;
    friend bool user::purchase(good& g);
    good();
    good(int id,QString name,double price,int num);//货物的初始构造函数，需要输入货物的id 货物名 价格 剩余数量
    QString getname() const;
    int getid() const;
    double getprice() const;
    int getnum() const;

    int id;
    QString name;
    double price;
    int num;
private:

};
