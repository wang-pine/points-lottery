#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>
#include <QString>
#include <QVBoxLayout>
#include <QPushButton>
namespace Ui {
class UserInfo;
}
class UserInfo : public QWidget
{
    Q_OBJECT
public:
    explicit UserInfo(QWidget *parent = nullptr);
    bool setInfo(QString ID,QString name,QString score,QString money);
    void setName(QString name);
    void setID(QString id);
    void setScore(QString score);
    void setHead(QString head);
    void setMoney(QString money);
    void addBtnClik();
    void addTENBtnClik();
    QVBoxLayout *ui_vLayWin;
    QPushButton *addONEBtn;
    QPushButton *addTENBtn;
signals:
    void addONE_clicked();
    void addTEN_clicked();
private:
    Ui::UserInfo *ui;
    bool addONEBtnJUD = false;
    bool addTENBtnJUD = false;

};

#endif // USERINFO_H
