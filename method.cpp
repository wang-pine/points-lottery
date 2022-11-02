#include "method.h"
good idsearch::seek(QVector<good> goodlist, int n)
{
    int i = 0;
    good* good1 = new good();
    do
    {
        if (n == goodlist[i].getid())
        {
            return goodlist[i];
            break;
        }
        i += 1;
    } while (i < goodlist.size());
    if (i == goodlist.size())
    {
        printf("货物不存在");
        return *good1;
    }
}
user idsearch::seek(QVector<user> userlist, int n)
{
    int i = 0;
    user user;
    do
    {
        if (n == userlist[i].getid())
        {
            return userlist[i];
            break;
        }
        i += 1;
    } while (i < userlist.size());
    if (i == userlist.size())
    {
        printf("用户不存在");
        return user;
    }
}
void idsearch::sort(QVector<good>& goodlist)
{}
void idsearch::sort(QVector<user>& userlist)
{}
void idsort::sort(QVector<good>& goodlist)
{
    int i,k=0;
    good mingood;
    for (i = 0; i < goodlist.size(); i++)
    {
        if (goodlist[k].getid()>goodlist[i].getid())
        {
            mingood=goodlist[i];
            goodlist[i] = goodlist[k];
            goodlist[k] = mingood;

        }
    }
}
void idsort::sort(QVector<user>& userlist)
{
    int i, k = 0;
    user minuser;
    for (i = 0; i < userlist.size(); i++)
    {
        if (userlist[k].getid() > userlist[i].getid())
        {
            minuser = userlist[i];
            userlist[i] = userlist[k];
            userlist[k] = minuser;

        }
    }
}
good idsort::seek(QVector<good> goodlist, int n)
{
    good g;
    return g;
}
user idsort::seek(QVector<user> userlist, int n)
{
    user u;
    return u;
}
