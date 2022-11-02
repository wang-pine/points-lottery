#ifndef ADDONE_H
#define ADDONE_H

#include "gamble.h"
#include <QVector>
#include <QString>

class addONE
{
public:
    addONE(QString id);
    void gambONE();
    void setUserID(QString id);

private:
    QString userID_str;
    double rate = 0.5;
    int id_Int;/*读入gamble.txt*/
    int score = 160;
};

#endif // ADDONE_H
