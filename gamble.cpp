#include "gamble.h"
#include <QDebug>
gamble::gamble(double rate, int id,int score)
{
    *game = { 0 };
    this->score=score;
    prize p;
    p.id = id;
    p.rate = rate;
    int n = N * rate;
    temp_n = n;
    int i;
    for ( i = 0; i < n; i++)
    {
        game[i] = id;
    }
    temp_arr = game;
    point = n;
    prizelist.push_back(p);
}
bool gamble::add(int id, double rate)
{
    prize p;
    p.id = id;
    p.rate = rate;
    p.n = N * rate;
    int n = p.n;
    if (point + n > N)
    {
        qDebug() << "奖池已满" << endl;
        return false;
    }
    int i;
    for (i = point; i < (point + n); i++)
    {
        game[i] = id;
    }
    point += n;
    prizelist.push_back(p);
    return true;
}
bool gamble::adjustgood(int id, double rate)
{
    if (rate < 0||rate>1)
        return false;
    int i,n,k;
    int sum = 0;
    double rate3 = 0;
    double rate2=-2;
    for (i = 0; i < prizelist.size(); i++)
    {
        if (id == prizelist[i].id)
        {
            rate2 = rate - prizelist[i].rate;
            prizelist[i].rate = rate;
            break;
        }
    }
    for (i = 0; i < prizelist.size(); i++)
    {
        rate3 += prizelist[i].rate;

    }
    if(rate3>1)
    {
        cout << "错误" << endl;
        return false;
    }
    if (rate2 == -2)
    {
        cout << "未找到该奖品" << endl;
        return false;
    }
    k = i;
    if (rate2 < 0)
    {
        n = -N * rate2;
        for (i = 0; i <= k; i++)
            sum += prizelist[i].n;
        for (i = sum; i < N; i++)
            game[i - n] = game[i];
        for (i = N - n; i < N; i++)
            game[i] = 0;
        return true;
    }
    n = rate2 * N;
    for (i = 0; i <= k; i++)
        sum += prizelist[i].n;
    for (i = sum; i < N - n; i++)
        game[i + n] = game[i];
    for (i = sum; i < sum + n; i++)
        game[i] = id;
    return true;
}
good gamble::start(user &u,const QVector<good>&goodlist)
{
    good good;
    if (u.t.score < score)
    {
        qDebug() << "积分不足" << endl;
        return good;
    }
    method* m = new idsearch();
    u.t.score -= score;
    if (u.t.info >= 90)
    {
        good = m->seek(goodlist, prizelist[0].id);
        qDebug() << "恭喜中奖" << good.getname() << endl;
        u.t.info -=90;
        return good;
        //delete m;
    }
    unsigned seed = time(0)*u.t.score;
    srand(seed);
    int random = rand() % N + 1;
    qDebug()<<"我现在的random值是"<<random<<endl;
    random_Value = random;
    good=m->seek(goodlist, game[random]);
    qDebug() << "恭喜抽中" << good.getname() << endl;
    u.t.info += 1;
    return good;
    delete(m);

}
QVector<good> tentimes(user& u, QVector<good>goodlist, gamble g1)
{
    int i;
    QVector<good> prize;
    for (i = 0; i < 10; i++)
    {
        prize.push_back(g1.start(u, goodlist));
        //sleep(1000);
    }
    return prize;
}
