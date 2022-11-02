#include "gamblemanage.h"
#include "ui_GambleManage.h"
#include <QStandardItemModel>
#include <QTableView>
#include <QVBoxLayout>
GambleManage::GambleManage(QWidget *parent):
    QWidget(parent),
    ui(new Ui::GambleManage)
{
    ui->setupUi(this);
    QVBoxLayout *ui_vLayWin = new QVBoxLayout;
    ui_vLayWin->addWidget(ui->histView);
    ui_vLayWin->addWidget(ui->addBtn);
    ui_vLayWin->addWidget(ui->deleteBtn);
    ui_vLayWin->addWidget(ui->infoEdt);
    ui->infoEdt->setPlaceholderText(tr("输入奖池文本"));
    ui_vLayWin->addWidget(ui->saveBtn);
    ui_vLayWin->addStretch();

//    histModel = new QStandardItemModel();
//    histModel = new QStandardItemModel();
//    histModel->setColumnCount(3);
//    histModel->setHorizontalHeaderLabels(QStringList() << "check" << "ID" << "info");
//    ui->histView->setModel(histModel);

    QMargins margin = ui_vLayWin->contentsMargins();
    margin.setTop(0);
    ui_vLayWin->setContentsMargins(margin);
    setLayout(ui_vLayWin);

    connect(ui->addBtn,&QPushButton::clicked,[=](){emit add_clicked();});
    connect(ui->deleteBtn,&QPushButton::clicked,[=](){emit delete_clicked();});
    connect(ui->saveBtn,&QPushButton::clicked,[=](){emit save_clicked();});
}
QString GambleManage::getText(){
    return ui->infoEdt->toPlainText();
}
void GambleManage::setGambleModel(QStandardItemModel *model){
    ui->histView->setModel(model);
}
