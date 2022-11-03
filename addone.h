#ifndef ADDONE_H
#define ADDONE_H

#include "gamble.h"
#include <QVector>
#include <QString>

class addONE
{
public:
    addONE(QString id);
    void gambONE(QString first_prize);
    void setUserID(QString id);
    QString prize_get;
    int return_num = 0;
private:
    QString userID_str;
    double rate = 0.1;
    int ID_get = 0;
    int id_Int;/*读入gamble.txt*/
    int score = 160;
};

#endif // ADDONE_H
