/********************************************************************************
** Form generated from reading UI file 'UserTab.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERTAB_H
#define UI_USERTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "jnavibutton.h"

QT_BEGIN_NAMESPACE

class Ui_UserTab
{
public:
    JNaviButton *Tab1;
    JNaviButton *Tab2;

    void setupUi(QWidget *UserTab)
    {
        if (UserTab->objectName().isEmpty())
            UserTab->setObjectName(QString::fromUtf8("UserTab"));
        UserTab->resize(400, 300);
        Tab1 = new JNaviButton(UserTab);
        Tab1->setObjectName(QString::fromUtf8("Tab1"));
        Tab1->setGeometry(QRect(10, 110, 93, 28));
        Tab2 = new JNaviButton(UserTab);
        Tab2->setObjectName(QString::fromUtf8("Tab2"));
        Tab2->setGeometry(QRect(110, 110, 93, 28));

        retranslateUi(UserTab);

        QMetaObject::connectSlotsByName(UserTab);
    } // setupUi

    void retranslateUi(QWidget *UserTab)
    {
        UserTab->setWindowTitle(QCoreApplication::translate("UserTab", "Form", nullptr));
        Tab1->setText(QCoreApplication::translate("UserTab", "Tab1", nullptr));
        Tab2->setText(QCoreApplication::translate("UserTab", "Tab2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserTab: public Ui_UserTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERTAB_H
