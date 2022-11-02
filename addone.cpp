#include "addone.h"
#include <QFile>
#include <QDir>
#include <QTextCodec>
#include <QDebug>
#include <QString>
#include <QVector>

addONE::addONE(QString str){
    this->userID_str = str;
}
void addONE::gambONE(){
     QVector<good> goodlist;
    //gamble gam(rate,id_Int,score);

    QString t1_id;
    QString t1_name;
    QString t1_score;
    QString t1_info;
    QString t1_money;

    //读入本地文件user
    /*id,name,info,score,money*/
    QFile temp_file1(QDir::currentPath() + "/txt/user.txt");
    temp_file1.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray arr1;
    QTextCodec *tc = QTextCodec::codecForName("UTF-8");
    bool OK = false;
    while(!temp_file1.atEnd()){
        if(OK) break;
        arr1 = temp_file1.readLine();
        qDebug() << arr1;
        int len = arr1.size();
        QString ptr = tc->toUnicode(arr1);
        QString temp_str;
        int countT = 0;
        for(int i = 0;i < len;i ++){
            if(ptr[i] != '\t' && ptr[i]!='\n'){
                temp_str.push_back(ptr[i]);
            }else{
                if(temp_str == userID_str){
                    OK = true;
                }
                countT ++;
                if(countT == 1){t1_id = temp_str;}//id
                if(countT == 2){t1_name = temp_str;}//name
                if(countT == 3){t1_info = temp_str;}//info
                if(countT == 4){t1_score = temp_str;}//score
                if(countT == 5){t1_money = temp_str;}//money
                temp_str = "";
            }
        }
    }
    temp_file1.close();
    infotable t1 = {t1_id.toInt(),t1_name,t1_info.toInt(),t1_score.toInt(),t1_money.toInt()};//新建用户结构体
    qDebug() <<"目前的用户数据的读出为"<< t1.id << t1.name << t1.info << t1.score << t1.money;
    //temp_file1
    qDebug() << "用户文件读出完毕";
    //读入货物数据
    /*id,name,price,num*/
    /*
    good(int id,string name,double price,int num);
    */
    QFile temp_file2(QDir::currentPath() + "/txt/goods.txt");
    bool ok2 = temp_file2.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray arr2;
    QTextCodec *tc2 = QTextCodec::codecForName("UTF-8");
    if(ok2)qDebug() << "进入货物文件进行操作";
    else qDebug() << "进入失败";

    while(!temp_file2.atEnd()){
        arr2 = temp_file2.readLine();
        qDebug() << "当前货物文件中的行数"<< arr2;
        int len = arr2.size();
        QString ptr = tc2->toUnicode(arr2);

        QString temp_str;
        int countT = 0;
        QString ID_str;
        QString name_str;
        QString price_str;
        QString num_str;

        for(int i = 0;i < len;i ++){
            if(ptr[i] != '\t' && ptr[i]!='\n'){
                temp_str.push_back(ptr[i]);
            }else{
                countT ++;
                if(countT == 1){ID_str = temp_str;qDebug() << "货物ID"<< ID_str;}//id
                if(countT == 2){t1_name = temp_str; name_str = temp_str;}//name
                if(countT == 3){t1_info = temp_str; price_str = temp_str;}//info
                if(countT == 4){
                    qDebug() << "tempGood生成";
                    t1_score = temp_str;
                    num_str = temp_str;
                    countT = 0;
                    good tempGood = {ID_str.toInt(),name_str,price_str.toDouble(),num_str.toInt()};
                    qDebug() <<"目前所有的货物数据是" << tempGood.id << tempGood.name << tempGood.price << tempGood.num;
                    goodlist.push_back(tempGood);
                }//score
                temp_str = "";
            }
        }
    }
    //qDebug() << "所有的goodlist是" << goodlist;
    temp_file1.close();
    QVector<good>::iterator num;
    for(num = goodlist.begin();num != goodlist.end();num ++){
        qDebug() << num->id << ":" << num->name << ":" << num->price << ":" << num->num;
    }
    /*
     *
    gamble(double rate, int id,int score);//gamble类的构造函数，需要传入一等奖的概率，货物id和抽奖所需积分
    good start(user &u,const QVector<good>&goodlist);//抽奖开始，需要传入进行抽奖的用户和货物列表（整个货物列表）
    bool add(int id, double rate);//增添奖池深度，
    bool adjustgood(int id, double rate);//调奖池物品的概率,若要删除就设置rate=0
    QVector<prize> prizelist;//奖池奖品数组,prizelist[1]是概率最低的奖品（一等奖）。
     *
     */
    gamble gam(rate,100005,score);
    user user_temp(t1);
    gam.add(100007,0.5);
    good prize = gam.start(user_temp,goodlist);
    qDebug() << "最终奖品是"  << prize.name.toUtf8();
    qDebug() << "此时在gamble中的random的值是" << gam.random_Value;
    struct prize
    {
        int id=0;
        double rate=0;
        int n = rate * 1000;
    };
    QVector<struct::prize>::iterator num2;
    for(num2 = gam.prizelist.begin();num2 != gam.prizelist.end();num2 ++){
        qDebug() << "奖品表是" << num2->id << ":" << num2->rate <<":"<< num2->n;
    }
    qDebug() << "此时gamble中n的数值是" << gam.temp_n;
    qDebug() << "所需要的game的值为";
//    for(int i= 0;i <1000;i ++){
//        qDebug() <<gam.temp_arr[i];
//    }
    /*-----------*/
}
void addONE::setUserID(QString id){
    this->userID_str = id;
    id_Int = userID_str.toInt();
}
