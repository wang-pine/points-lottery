/********************************************************************************
** Form generated from reading UI file 'AdminTab.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINTAB_H
#define UI_ADMINTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "jnavibutton.h"

QT_BEGIN_NAMESPACE

class Ui_AdminTab
{
public:
    JNaviButton *Tab1;
    JNaviButton *Tab2;
    JNaviButton *Tab3;

    void setupUi(QWidget *AdminTab)
    {
        if (AdminTab->objectName().isEmpty())
            AdminTab->setObjectName(QString::fromUtf8("AdminTab"));
        AdminTab->resize(418, 116);
        Tab1 = new JNaviButton(AdminTab);
        Tab1->setObjectName(QString::fromUtf8("Tab1"));
        Tab1->setGeometry(QRect(20, 30, 93, 28));
        Tab2 = new JNaviButton(AdminTab);
        Tab2->setObjectName(QString::fromUtf8("Tab2"));
        Tab2->setGeometry(QRect(130, 30, 93, 28));
        Tab3 = new JNaviButton(AdminTab);
        Tab3->setObjectName(QString::fromUtf8("Tab3"));
        Tab3->setGeometry(QRect(240, 30, 93, 28));

        retranslateUi(AdminTab);

        QMetaObject::connectSlotsByName(AdminTab);
    } // setupUi

    void retranslateUi(QWidget *AdminTab)
    {
        AdminTab->setWindowTitle(QCoreApplication::translate("AdminTab", "AdminTab", nullptr));
        Tab1->setText(QCoreApplication::translate("AdminTab", "Tab1", nullptr));
        Tab2->setText(QCoreApplication::translate("AdminTab", "Tab2", nullptr));
        Tab3->setText(QCoreApplication::translate("AdminTab", "Tab3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminTab: public Ui_AdminTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINTAB_H
