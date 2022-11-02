#include "usermanage.h"
#include "ui_UserManage.h"

#include <QVBoxLayout>
#include<QAction>
#include <QDebug>
UserManage::UserManage(QWidget *parent):
    QWidget(parent),
    ui(new Ui::UserManage)
{
    ui->setupUi(this);

    QVBoxLayout *ui_vLayWin = new QVBoxLayout;
    ui_vLayWin->addWidget(ui->openBtn);
    ui_vLayWin -> addWidget(ui->addBtn);
    ui_vLayWin ->addWidget(ui->saveBtn);
    //ui_vLayWin->addWidget(ui->coverBtn);
    ui_vLayWin ->addWidget(ui->searchLEd);
    ui_vLayWin -> addWidget(ui->searchBtn);
    ui_vLayWin->addStretch();

    ui->searchLEd->setTextMargins(10,1,1,1);
    ui->searchLEd->setStyleSheet("#ui->searchLEd{qproperty-icon{image:url(:/Icon/search.png);}}""#ui->searchLEd{qproperty-size:20px;}");

    QAction *searchAction = new QAction(ui->searchLEd);
    searchAction->setIcon(QIcon(":/Icon/search.png"));

    ui->searchBtn->setIcon(QIcon(":/Icon/search.png"));
    //searchBtn->setStyleSheet("QPushButton{border:none;background:transparent;}");
    //searchBtn->resize(40,40);

    ui->searchLEd->addAction(searchAction,QLineEdit::LeadingPosition);
    ui->searchLEd->setPlaceholderText("搜索");
    ui->searchLEd->setFocus();

    QMargins margin = ui_vLayWin->contentsMargins();
    margin.setTop(0);
    ui_vLayWin->setContentsMargins(margin);
    setLayout(ui_vLayWin);

    connect(ui->addBtn,&QPushButton::clicked,[=](){emit add_clicked();});
    connect(ui->openBtn,&QPushButton::clicked,[=](){emit open_clicked();});
    connect(ui->searchBtn,&QPushButton::clicked,[=](){emit search_clicked();});
    connect(ui->saveBtn,&QPushButton::clicked,[=](){emit save_clicked();});
    //connect(ui->coverBtn,&QPushButton::clicked,[=](){emit cover_clicked();});
}
QString UserManage::getSearchValue(){
    return ui->searchLEd->text().trimmed();
}
UserManage::~UserManage()
{
    delete ui;
}
