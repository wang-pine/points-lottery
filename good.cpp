#include "good.h"
good::good(int id, QString name, double price, int num)
{
    this->id = id;
    this->name = name;
    this->price = price;
    this->num = num;
}
good::good()
{
    id = 0;
    name = "none";
    price = 0;
    num = 0;

}
int good::getid() const
{
    return id;
}
int good::getnum() const
{
    return num;
}
QString good::getname() const
{
    return name;
}
double good::getprice() const
{
    return price;
}
bool user::purchase(good& g)
{
    if (g.num == 0)
        return false;
    g.num -= 1;
    t.score += g.price / 10;
    return true;

}
