#include "usermainwindow.h"
#include <QHeaderView>
#include <QString>
#include <QFile>
#include <QDir>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QTextCodec>
#include "gamble.h"
#include "addone.h"
#include "QDebug"
#include "usertab.h"
UserMainWindow::UserMainWindow(QWidget *parnet):
    QWidget(parnet),
    ui_wSatckTabs(new QStackedWidget)
{
    this -> resize(960,540);

    setAttribute(Qt::WA_StyledBackground);

    UserTab *ui_tab = new UserTab(this);
    ui_tab->setTitleHeight(50);
    ui_info = new UserInfo(this);
    ui_info2 = new UserInfo(this);

    ui_buy = new QTextBrowser(this);
    ui_gamble = new QTextBrowser(this);
    QPushButton *btnONE = new QPushButton();
    btnONE->setText("单抽");
    buySplitter = new QSplitter;
    buySplitter->addWidget(ui_info2);
    buySplitter->addWidget(ui_buy);
    buySplitter->setStretchFactor(0,1);
    buySplitter->setStretchFactor(1,4);
    ui_wSatckTabs->addWidget(buySplitter);

    gambleSplitter = new QSplitter;
    gambleSplitter->addWidget(ui_info);
    gambleSplitter->addWidget(ui_gamble);
    gambleSplitter->setStretchFactor(0,1);
    gambleSplitter->setStretchFactor(1,4);
    ui_wSatckTabs->addWidget(gambleSplitter);

    QVBoxLayout *ui_vLayWindow = new QVBoxLayout(this);
    ui_vLayWindow->addWidget(ui_tab);
    ui_vLayWindow->addWidget(ui_wSatckTabs);
    ui_vLayWindow->setMargin(0);
    setLayout(ui_vLayWindow);
    connect(ui_tab,&UserTab::tab1_Clicked,[=](){ui_wSatckTabs->setCurrentWidget(buySplitter);});
    connect(ui_tab,&UserTab::tab2_Clicked,[=]{ui_wSatckTabs->setCurrentWidget(gambleSplitter);ui_info->addBtnClik();ui_info->addTENBtnClik();});
    connect(ui_info,&UserInfo::addONE_clicked,[=](){gambONE(UID);});
}
void UserMainWindow::setUid(QString id){
    this->UID=id;
    ui_info->setID(id);ui_info2

            ->setID(id);
    qDebug() << "在usermainwindow中UID是" << this->UID;
    QFile info(QDir::currentPath() + "/txt/userinfo.txt");
    info.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray arr;
    QTextCodec *tc = QTextCodec::codecForName("UTF-8");
    bool OK = false;
    QString head;
    QString phone;
    while(!info.atEnd()){
        if(OK) break;
        arr = info.readLine();
        qDebug() << arr;
        QString ptr;
        ptr = tc->toUnicode(arr);
        int len = arr.size();
        QString temp_str;
        int countT = 0;
        for(int i = 0;i < len;i ++){
            if(ptr[i] != '\t' && ptr[i] != '\n'){
                temp_str.push_back(ptr[i]);
                //qDebug() << temp_str;
            }else{
                countT ++;
                if(countT == 3){head = temp_str;qDebug() << "head" << head;ui_info->setHead(head);ui_info2->setHead(head);}
                if(countT == 4){phone = temp_str;qDebug() << "phone"<< phone;}
                if(temp_str == UID){
                    qDebug() << "捕捉到uid" << UID;
                    OK = true;
                }
                temp_str = "";
            }
        }
    }
    info.close();
    QString name;
    QString score;
    QString money;

    QFile info2(QDir::currentPath() + "/txt/user.txt");
    info2.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray arr2;
    QTextCodec *tc2 = QTextCodec::codecForName("UTF-8");
    bool OK2 = false;
    while(!info2.atEnd()){
        if(OK2)break;
        arr2 = info2.readLine();
        QString ptr2;
        ptr2 = tc2->toUnicode(arr2);
        int len2 = arr2.size();
        QString temp2;
        int countT = 0;
        for(int i = 0;i < len2;i ++){
            if(ptr2[i] != '\t' && ptr2[i] !='\n'){
                temp2.push_back(ptr2[i]);
            }else{
                countT ++;
                qDebug() << temp2;
                if(countT == 2){name = temp2;qDebug() << "name" << name;ui_info->setName(name);ui_info2->setName(name);};
                if(countT == 3){score = temp2;qDebug() << "score" << score;ui_info->setScore(score);ui_info2->setScore(score);};
                if(countT == 4){money = temp2;ui_info->setMoney(money);ui_info2->setMoney(money);};
                if(temp2 == UID){
                    qDebug() << "捕捉到uid" << UID;
                    OK = true;
                }
                temp2 = "";
            }
        }
    }
    info2.close();

}
void UserMainWindow::gambONE(QString id){
    addONE add(id);
    add.gambONE();
}
