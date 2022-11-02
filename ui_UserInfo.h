/********************************************************************************
** Form generated from reading UI file 'UserInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFO_H
#define UI_USERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInfo
{
public:
    QPushButton *headBtn;
    QLabel *UIDLbl;
    QLabel *nameLbl;
    QLabel *scoreLbl;
    QLabel *moneyLbl;

    void setupUi(QWidget *UserInfo)
    {
        if (UserInfo->objectName().isEmpty())
            UserInfo->setObjectName(QString::fromUtf8("UserInfo"));
        UserInfo->resize(400, 300);
        headBtn = new QPushButton(UserInfo);
        headBtn->setObjectName(QString::fromUtf8("headBtn"));
        headBtn->setGeometry(QRect(140, 20, 101, 91));
        UIDLbl = new QLabel(UserInfo);
        UIDLbl->setObjectName(QString::fromUtf8("UIDLbl"));
        UIDLbl->setGeometry(QRect(150, 130, 41, 16));
        nameLbl = new QLabel(UserInfo);
        nameLbl->setObjectName(QString::fromUtf8("nameLbl"));
        nameLbl->setGeometry(QRect(150, 160, 72, 15));
        scoreLbl = new QLabel(UserInfo);
        scoreLbl->setObjectName(QString::fromUtf8("scoreLbl"));
        scoreLbl->setGeometry(QRect(150, 190, 72, 15));
        moneyLbl = new QLabel(UserInfo);
        moneyLbl->setObjectName(QString::fromUtf8("moneyLbl"));
        moneyLbl->setGeometry(QRect(150, 220, 72, 15));

        retranslateUi(UserInfo);

        QMetaObject::connectSlotsByName(UserInfo);
    } // setupUi

    void retranslateUi(QWidget *UserInfo)
    {
        UserInfo->setWindowTitle(QCoreApplication::translate("UserInfo", "Form", nullptr));
        headBtn->setText(QString());
        UIDLbl->setText(QCoreApplication::translate("UserInfo", "   UID:", nullptr));
        nameLbl->setText(QCoreApplication::translate("UserInfo", "   name:", nullptr));
        scoreLbl->setText(QCoreApplication::translate("UserInfo", "   score:", nullptr));
        moneyLbl->setText(QCoreApplication::translate("UserInfo", "   money:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInfo: public Ui_UserInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFO_H
