#include "usertab.h"
#include "ui_UserTab.h"
#include <QHBoxLayout>
#include <QFile>

UserTab::UserTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserTab)
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
    //QPushButton *headBtn = new QPushButton(this);
    //headBtn->resize(100,100);
    QHBoxLayout *ui_hLayNaviButton = new QHBoxLayout(this);
    //ui_hLayNaviButton->addWidget(headBtn);
    ui_hLayNaviButton->addWidget(ui->Tab1);
    ui_hLayNaviButton->addWidget(ui->Tab2);
    ui_hLayNaviButton->addStretch();
    ui_hLayNaviButton->setMargin(0);
    ui_hLayNaviButton->setSpacing(0);
    ui->Tab1->setChecked(true);
    ui->Tab1->setText(tr("购物"));
    ui->Tab2->setText(tr("抽奖"));


    connect(ui->Tab1,&JNaviButton::clicked,[=](){emit tab1_Clicked();});
    connect(ui->Tab2,&JNaviButton::clicked,[=](){emit tab2_Clicked();});

     m_listNaviButtons << ui->Tab1 << ui->Tab2;
     setLayout(ui_hLayNaviButton);
}
void UserTab::setTitleHeight(int height){
    if(m_titleHeight != height) {
        m_titleHeight = height;
        setFixedHeight(m_titleHeight);
        for(auto btn : m_listNaviButtons) {
            btn->setFixedHeight(m_titleHeight);
            btn->setFixedWidth(m_titleHeight * 3);
            btn->setTextAlign(JNaviButton::TextAlign_Center);
        }
    }
}
