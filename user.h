#pragma once
#include"good.h"
#include <QString>
struct codetable
{
    int id;
    QString password;
};
struct infotable
{
    int id;
    QString name;
    int info;
    int score;
    int money;
};
class good;
class user
{
public:
    friend class gamble;
    user(infotable t1);
    bool purchase(good &g);//购买函数需要传入要购买的商品

    user();
    int getid();
    QString getname();
private:
    codetable c;
    infotable t;
    QString getpassword() const;
    bool comp(QString str) const;//密码比对函数，比较输入的密码和用户密码，相同则返回true。


};

