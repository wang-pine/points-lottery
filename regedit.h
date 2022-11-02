#ifndef REGIDET_H
#define REGIDET_H

#include <QWidget>
#include <QLineEdit>
namespace Ui {
class Regedit;
}
class Regedit:public QWidget
{
    Q_OBJECT
public:
    explicit Regedit(QWidget *parent = 0);
private:
    int headID = 1;
    Ui::Regedit *ui;
    void regedit();
    QLineEdit *nameLEd;
    QLineEdit *pwdLEd;
    QLineEdit *confirmLEd;
    QLineEdit *phoneNumberLEd;
    QString UID;
};

#endif // REGIDET_H
