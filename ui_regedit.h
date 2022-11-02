/********************************************************************************
** Form generated from reading UI file 'regedit.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGEDIT_H
#define UI_REGEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Regedit
{
public:
    QPushButton *saveBtn;

    void setupUi(QWidget *Regedit)
    {
        if (Regedit->objectName().isEmpty())
            Regedit->setObjectName(QString::fromUtf8("Regedit"));
        Regedit->resize(602, 392);
        saveBtn = new QPushButton(Regedit);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        saveBtn->setGeometry(QRect(220, 90, 93, 28));

        retranslateUi(Regedit);

        QMetaObject::connectSlotsByName(Regedit);
    } // setupUi

    void retranslateUi(QWidget *Regedit)
    {
        Regedit->setWindowTitle(QCoreApplication::translate("Regedit", "Form", nullptr));
        saveBtn->setText(QCoreApplication::translate("Regedit", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Regedit: public Ui_Regedit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGEDIT_H
