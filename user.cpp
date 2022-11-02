#include "good.h"
user::user(infotable t1)
{
//    c.id = c1.id;
//    c.password = c1.password;
    t.id = t1.id;
    t.info = t1.info;
    t.money = t1.money;
    t.name = t1.name;
    t.score = t1.score;
}
user::user()
{
    c.id = t.id = 0;
    c.password = "  ";
    t.info = t.money = t.score = 0;
        t.name = "none";
}
int user::getid()
{
    return t.id;
}
QString user::getname()
{
    return t.name;
}
QString user::getpassword() const
{
    return c.password;
}
bool user::comp(QString str) const
{
    if (str == c.password)
        return true;
    return false;
}
