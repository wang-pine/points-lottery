/********************************************************************************
** Form generated from reading UI file 'UserManage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGE_H
#define UI_USERMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserManage
{
public:
    QLineEdit *searchLEd;
    QPushButton *searchBtn;
    QPushButton *saveBtn;
    QPushButton *addBtn;
    QPushButton *openBtn;

    void setupUi(QWidget *UserManage)
    {
        if (UserManage->objectName().isEmpty())
            UserManage->setObjectName(QString::fromUtf8("UserManage"));
        UserManage->resize(303, 300);
        searchLEd = new QLineEdit(UserManage);
        searchLEd->setObjectName(QString::fromUtf8("searchLEd"));
        searchLEd->setGeometry(QRect(40, 240, 222, 21));
        searchBtn = new QPushButton(UserManage);
        searchBtn->setObjectName(QString::fromUtf8("searchBtn"));
        searchBtn->setGeometry(QRect(20, 200, 269, 28));
        saveBtn = new QPushButton(UserManage);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        saveBtn->setGeometry(QRect(60, 80, 158, 28));
        addBtn = new QPushButton(UserManage);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setGeometry(QRect(60, 40, 158, 28));
        openBtn = new QPushButton(UserManage);
        openBtn->setObjectName(QString::fromUtf8("openBtn"));
        openBtn->setGeometry(QRect(60, 10, 158, 28));

        retranslateUi(UserManage);

        QMetaObject::connectSlotsByName(UserManage);
    } // setupUi

    void retranslateUi(QWidget *UserManage)
    {
        UserManage->setWindowTitle(QCoreApplication::translate("UserManage", "Form", nullptr));
        searchBtn->setText(QString());
        saveBtn->setText(QCoreApplication::translate("UserManage", "\344\277\235\345\255\230", nullptr));
        addBtn->setText(QCoreApplication::translate("UserManage", "\346\267\273\345\212\240", nullptr));
        openBtn->setText(QCoreApplication::translate("UserManage", "\346\211\223\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserManage: public Ui_UserManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGE_H
