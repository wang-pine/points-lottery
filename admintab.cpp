#include "admintab.h"
#include "ui_AdminTab.h"
#include <QHBoxLayout>

AdminTab::AdminTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminTab)
{
    ui->setupUi(this);
    QHBoxLayout *ui_hLayNaviButton = new QHBoxLayout(this);
    ui_hLayNaviButton->addWidget(ui->Tab1);
    ui_hLayNaviButton->addWidget(ui->Tab2);
    ui_hLayNaviButton->addWidget(ui->Tab3);
    ui_hLayNaviButton->addStretch();
    ui_hLayNaviButton->setMargin(0);
    ui_hLayNaviButton->setSpacing(0);
    ui->Tab1->setChecked(true);

    ui->Tab1->setText(tr("用户管理"));
    ui->Tab2->setText(tr("商品管理"));
    ui->Tab3->setText(tr("抽奖管理"));
    connect(ui->Tab1,&JNaviButton::clicked,[=](){emit tab1_Clicked();});
    connect(ui->Tab2,&JNaviButton::clicked,[=](){emit tab2_Clicked();});
    connect(ui->Tab3,&JNaviButton::clicked,[=](){emit tab3_Clicked();});

    m_listNaviButtons << ui->Tab1 << ui->Tab2 << ui->Tab3;
    setLayout(ui_hLayNaviButton);
}

void AdminTab::setTitleHeight(int height)
{
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
