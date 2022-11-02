#pragma once
#include "good.h"
#include "user.h"
#include<QVector>
class method//定向方法抽象类，方便拓展功能，可以用ethod指针指向任意子类对象
{	public:
    virtual good seek(QVector<good> goodlist,int n) = 0;
    virtual user seek(QVector<user> userlist,int n) = 0;//n是你想要查找的ID
    virtual void sort(QVector<good> &goodlist) = 0;
    virtual void sort(QVector<user> &userlist) = 0;//改变传入的实参
};
class idsearch: public method
{
public:
    int i = 0;
    good seek(QVector<good> goodlist,int n);//排序和搜寻方法函数我觉得你用不上
    user seek(QVector<user> userlist,int n);
    void sort(QVector<good>& goodlist);
    void sort(QVector<user>& userlist);
};
class idsort : public method
{
public:
    void sort(QVector<good> &goodlist);
    void sort(QVector<user> &userlist);
    good seek(QVector<good> goodlist, int n);
    user seek(QVector<user> userlist, int n);

};
