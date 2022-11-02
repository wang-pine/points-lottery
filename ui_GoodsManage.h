/********************************************************************************
** Form generated from reading UI file 'GoodsManage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODSMANAGE_H
#define UI_GOODSMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GoodsManage
{
public:
    QPushButton *openBtn;
    QPushButton *addBtn;
    QPushButton *saveBtn;

    void setupUi(QWidget *GoodsManage)
    {
        if (GoodsManage->objectName().isEmpty())
            GoodsManage->setObjectName(QString::fromUtf8("GoodsManage"));
        GoodsManage->resize(400, 300);
        openBtn = new QPushButton(GoodsManage);
        openBtn->setObjectName(QString::fromUtf8("openBtn"));
        openBtn->setGeometry(QRect(130, 40, 93, 28));
        addBtn = new QPushButton(GoodsManage);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setGeometry(QRect(130, 90, 93, 28));
        saveBtn = new QPushButton(GoodsManage);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        saveBtn->setGeometry(QRect(130, 190, 93, 28));

        retranslateUi(GoodsManage);

        QMetaObject::connectSlotsByName(GoodsManage);
    } // setupUi

    void retranslateUi(QWidget *GoodsManage)
    {
        GoodsManage->setWindowTitle(QCoreApplication::translate("GoodsManage", "Form", nullptr));
        openBtn->setText(QCoreApplication::translate("GoodsManage", "\346\211\223\345\274\200", nullptr));
        addBtn->setText(QCoreApplication::translate("GoodsManage", "\346\267\273\345\212\240", nullptr));
        saveBtn->setText(QCoreApplication::translate("GoodsManage", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GoodsManage: public Ui_GoodsManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODSMANAGE_H
