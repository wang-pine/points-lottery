#include "userinfo.h"
#include "ui_UserInfo.h"
#include <QFile>
#include <QVBoxLayout>
#include <QPixmap>
#include <QDebug>
#include <QTimer>

UserInfo::UserInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInfo)
{
    ui->setupUi(this);
    //QSS加载
    QFile qss(":sty2.qss");
    if( qss.open(QFile::ReadOnly))
    {
        qDebug("open success");
        QString style = QLatin1String(qss.readAll());
        this->setStyleSheet(style);
        qss.close();
    }else{
        qDebug("Open failed");
    }
    setAttribute(Qt::WA_StyledBackground);

    ui_vLayWin = new QVBoxLayout;
    ui->headBtn->setFixedSize(100,100);
    ui_vLayWin->addWidget(ui->headBtn);
    ui_vLayWin->addWidget(ui->UIDLbl);
    ui_vLayWin->addWidget(ui->nameLbl);
    ui_vLayWin->addWidget(ui->moneyLbl);
    ui_vLayWin->addWidget(ui->scoreLbl);

    ui_vLayWin->addStretch();

    QMargins margin = ui_vLayWin->contentsMargins();
    margin.setTop(0);
    ui_vLayWin->setContentsMargins(margin);
    setLayout(ui_vLayWin);
    addONEBtn = new QPushButton();
    connect(this->addONEBtn,&QPushButton::clicked,[=](){emit addONE_clicked();qDebug() << "抽一发";});
    addTENBtn = new QPushButton();
    connect(this->addTENBtn,&QPushButton::clicked,[=](){emit addTEN_clicked();qDebug() << "抽十次";});
}
bool UserInfo::setInfo(QString ID,QString name,QString score,QString money){
    ui->UIDLbl->setText(tr("   ") + ID);
    ui->nameLbl->setText(tr("   ")+ name);
    ui->scoreLbl->setText(tr("   ") + score);
    ui->moneyLbl->setText(tr("   ") + money);
    return true;
}
void UserInfo::setName(QString name){
    ui->nameLbl->setText(tr("   ") + "name:" + name);
}
void UserInfo::setID(QString id){
    ui->UIDLbl->setText(tr("   ") + "UID:" + id);
}
void UserInfo::setScore(QString score){
    ui->scoreLbl->setText(tr("   ") + "score:" + score);
}
void UserInfo::setHead(QString head){
    int headID = head.toInt();
    switch(headID){
    case 1:
    {
        QPixmap pic;
        pic.load(tr(":/Head/man1.png"));
        ui->headBtn->setIcon(pic);
        ui->headBtn->setIconSize(QSize(80,80));
        break;
    }
    case 2:
    {
        QPixmap pic;
        pic.load(tr(":/Head/man2.png"));
        ui->headBtn->setIcon(pic);
        ui->headBtn->setIconSize(QSize(80,80));
        break;
    }
        break;
    case 3:
    {
        QPixmap pic;
        pic.load(tr(":/Head/man3.png"));
        ui->headBtn->setIcon(pic);
        ui->headBtn->setIconSize(QSize(80,80));
        break;
    }
        break;
    case 4:
    {
        QPixmap pic;
        pic.load(tr(":/Head/man4.png"));
        ui->headBtn->setIcon(pic);
        ui->headBtn->setIconSize(QSize(80,80));
        break;
    }
        break;
    case 5:
    {
        QPixmap pic;
        pic.load(tr(":/Head/man5.png"));
        ui->headBtn->setIcon(pic);
        ui->headBtn->setIconSize(QSize(80,80));
        break;
    }
        break;
    case 6:
    {
        QPixmap pic;
        pic.load(tr(":/Head/man6.png"));
        ui->headBtn->setIcon(pic);
        ui->headBtn->setIconSize(QSize(80,80));
        break;
    }
        break;
    case 7:
    {
        QPixmap pic;
        pic.load(tr(":/Head/woman1.png"));
        ui->headBtn->setIcon(pic);
        ui->headBtn->setIconSize(QSize(80,80));
        break;
    }
        break;
    case 8:
    {
        QPixmap pic;
        pic.load(tr(":/Head/woman2.png"));
        ui->headBtn->setIcon(pic);
        ui->headBtn->setIconSize(QSize(80,80));
        break;
    }
        break;
    case 9:
    {
        QPixmap pic;
        pic.load(tr(":/Head/woman3.png"));
        ui->headBtn->setIcon(pic);
        ui->headBtn->setIconSize(QSize(80,80));
        break;
    }
        break;
    case 10:
    {
        QPixmap pic;
        pic.load(tr(":/Head/woman4.png"));
        ui->headBtn->setIcon(pic);
        ui->headBtn->setIconSize(QSize(80,80));
        break;
    }
        break;
    case 11:
    {
        QPixmap pic;
        pic.load(tr(":/Head/woman5.png"));
        ui->headBtn->setIcon(pic);
        ui->headBtn->setIconSize(QSize(80,80));
        break;
    }
        break;
    case 12:
    {
        QPixmap pic;
        pic.load(tr(":/Head/woman6.png"));
        ui->headBtn->setIcon(pic);
        ui->headBtn->setIconSize(QSize(80,80));
        break;
    }
        break;
    default:
        break;
    }
}
void UserInfo::setMoney(QString money){
    ui->moneyLbl->setText(tr("   ")  + tr("money:")+ money);
}
void UserInfo::addBtnClik(){
    if(!addONEBtnJUD){
        addONEBtn->setText(tr("抽一次"));
        ui_vLayWin->addWidget(addONEBtn);
        addONEBtnJUD = true;
    }
}
void UserInfo::addTENBtnClik(){
    if(!addTENBtnJUD){
        addTENBtn->setText(tr("抽十次"));
        ui_vLayWin->addWidget(addTENBtn);
        addTENBtnJUD = true;
    }
}
void UserInfo::addBrowserClik(){
    if(!addBrowserJUD){
        text = new QTextBrowser(this);
        ui_vLayWin->addWidget(text);
        addBrowserJUD = true;
    }
}
void UserInfo::print(QString mes,QString score){
    QTimer tim;
    tim.setInterval(1000);
    this->text->append(tr("恭喜抽中:") + mes);
    this->text->append(tr("账户余额:") + score);
    tim.start();
    this->text->ensureCursorVisible();
}
