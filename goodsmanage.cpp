#include "goodsmanage.h"
#include "ui_GoodsManage.h"

#include <QVBoxLayout>
#include<QAction>

GoodsManage::GoodsManage(QWidget*parent):
    QWidget(parent),
    ui(new Ui::GoodsManage)
{
    ui->setupUi(this);
    QVBoxLayout *ui_vLayWin = new QVBoxLayout;
    ui_vLayWin->addWidget(ui->openBtn);
    ui_vLayWin->addWidget(ui->addBtn);
    //ui_vLayWin->addWidget(ui->delBtn);
    ui_vLayWin->addWidget(ui->saveBtn);
    ui_vLayWin->addStretch();

    QMargins margin = ui_vLayWin->contentsMargins();
    margin.setTop(0);
    ui_vLayWin->setContentsMargins(margin);
    setLayout(ui_vLayWin);


    connect(ui->addBtn,&QPushButton::clicked,[=](){emit add_clicked();});
    //connect(ui->delBtn,&QPushButton::clicked,[=](){emit delete_clicked();});
    connect(ui->openBtn,&QPushButton::clicked,[=](){emit open_clicked();});
    connect(ui->saveBtn,&QPushButton::clicked,[=](){emit save_clicked();});
}

