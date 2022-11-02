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
    QTextBrowser *ui_gamble;
    QTextBrowser *ui_buy;

    void gambONE(QString id);
private:
    QString UID;
    QStackedWidget *ui_wSatckTabs;

};

#endif // USERMAINWINDOW_H
