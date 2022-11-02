/********************************************************************************
** Form generated from reading UI file 'GambleManage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMBLEMANAGE_H
#define UI_GAMBLEMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GambleManage
{
public:
    QPushButton *addBtn;
    QTableView *histView;
    QPushButton *deleteBtn;
    QTextEdit *infoEdt;
    QPushButton *saveBtn;

    void setupUi(QWidget *GambleManage)
    {
        if (GambleManage->objectName().isEmpty())
            GambleManage->setObjectName(QString::fromUtf8("GambleManage"));
        GambleManage->resize(400, 572);
        addBtn = new QPushButton(GambleManage);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setGeometry(QRect(140, 140, 93, 28));
        histView = new QTableView(GambleManage);
        histView->setObjectName(QString::fromUtf8("histView"));
        histView->setGeometry(QRect(110, 0, 171, 131));
        deleteBtn = new QPushButton(GambleManage);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));
        deleteBtn->setGeometry(QRect(140, 170, 93, 28));
        infoEdt = new QTextEdit(GambleManage);
        infoEdt->setObjectName(QString::fromUtf8("infoEdt"));
        infoEdt->setGeometry(QRect(110, 200, 181, 87));
        saveBtn = new QPushButton(GambleManage);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        saveBtn->setGeometry(QRect(140, 310, 93, 28));

        retranslateUi(GambleManage);

        QMetaObject::connectSlotsByName(GambleManage);
    } // setupUi

    void retranslateUi(QWidget *GambleManage)
    {
        GambleManage->setWindowTitle(QCoreApplication::translate("GambleManage", "Form", nullptr));
        addBtn->setText(QCoreApplication::translate("GambleManage", "\346\267\273\345\212\240\345\245\226\345\223\201", nullptr));
        deleteBtn->setText(QCoreApplication::translate("GambleManage", "\345\210\240\351\231\244\345\215\241\346\261\240", nullptr));
        saveBtn->setText(QCoreApplication::translate("GambleManage", "\344\270\212\347\272\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GambleManage: public Ui_GambleManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMBLEMANAGE_H
