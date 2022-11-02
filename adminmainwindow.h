#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

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

#include "admintab.h"
#include "usermanage.h"
#include "goodsmanage.h"
#include "gamblemanage.h"

class AdminMainWindow:public QWidget
{
public:
    explicit AdminMainWindow(QWidget *parent = 0);
    QStandardItemModel *userModel;
    QStandardItemModel *goodsModel;
    QStandardItemModel *gambleModel;//奖池信息
    QStandardItemModel *prizeModel;//奖品信息
    QString get_str( char *s, int size, const char ch='\t' );
public slots:
    void addUserTableRow();
    void saveUserTable();
    void searchUserElem();
    void openUserTable();

    void addGoodsTableRow();
    void saveGoodsTable();
    void openGoodsTable();

    void getSearchValue(QString str);

    void openGambleInfo();
    void addPrize();
    void pushGamble();
    void delGambleInfo();
private:
    UserManage *ui_user;
    QTableView *ui_userWidget;
    QSplitter *userSplitter;
    int userVaribleRows;
    int userAddBtnCount = 0;//统计按了几次add按钮

    GoodsManage *ui_goods;
    QTableView *ui_goodWidget;
    QSplitter *goodSplitter;
    int goodsVaribleRows;
    int goodsAddBtnCount = 0;

    GambleManage *ui_gamble;
    QTableView *ui_gambleWidget;
    QSplitter *gambleSplitter;
    int histCount = 0;

    QStackedWidget *ui_wSatckTabs;
};

#endif // ADMINMAINWINDOW_H
