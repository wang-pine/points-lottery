#ifndef USERMAINWINDOW_H
#define USERMAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QTableView>
#include <QTextEdit>
#include <QSplitter>
#include <QHBoxLayout>
#include <QSplitter>
#include<QStackedWidget>
#include <QTextBrowser>
#include <QStandardItemModel>
#include <QTableView>

#include "userinfo.h"
class UserMainWindow:public QWidget
{
    //friend class LoginWindow;
public:
    explicit UserMainWindow(QWidget *parent = 0);
    void setUid(QString id);
    QLabel *name;
    QLabel *ID;
    UserInfo *ui_info;
    UserInfo *ui_info2;
    QSplitter *buySplitter;
    QSplitter *gambleSplitter;
    QTableView *ui_gamble;
    QStandardItemModel *gambleModel;
    QTextBrowser *ui_buy;

    QString gambONE(QString id);
    QString priz;
    void openGamble();
private:
    QString UID;
    QStackedWidget *ui_wSatckTabs;
    QString score_str;
    QString first_prize_str;
    int first_prize_num = 1;
    bool JUD = false;
};

#endif // USERMAINWINDOW_H
