#pragma once
#include<cstdlib>
#include"good.h"
#include"user.h"
#include"method.h"
#include<QVector>
//#include<ctime>
#include <QTime>
struct prize
{
    int id = 0;
    double rate = 0;
    int n = rate * 1000;
};
class good;
class user;
class gamble
{
public:
    gamble(double rate, int id,int score);//gamble类的构造函数，需要传入一等奖的概率，货物id和抽奖所需积分
    good start(user &u,const QVector<good>&goodlist);//抽奖开始，需要传入进行抽奖的用户和货物列表（整个货物列表）
    bool add(int id, double rate);//增添奖池深度，
    bool adjustgood(int id, double rate);//调奖池物品的概率,若要删除就设置rate=0
    QVector<prize> prizelist;//奖池奖品数组,prizelist[1]是概率最低的奖品（一等奖）。
    int random_Value = 0;
    int temp_n = 0;
    int *temp_arr;
private:
    int N=1000;//边界数
    int* game = new int[N];//抽奖范围数组,数组里放商品id。
    int point = 0;//插入点（你不需要管）
    int score;//该奖池需要消耗的积分
};
QVector<good> tentimes(user& u, QVector<good>goodlist, gamble g1);//十连抽，需要输入用户，货物列表 奖池（抽奖类的具体对象）。


