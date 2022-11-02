#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include<QDialog>

#include "regedit.h"
#include "forget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    int loginJud;               //用于判定登录的是user还是admin
    int regJud = 0;                 //注册按钮使用判定
    int forgetJud = 0;              //忘记密码按钮用于判定
    QString userJud;//用于判断用户的ID
signals:

public slots:
    void login();//点击登录按钮后执行的槽函数
signals:
    void registersig();
    void forgetSig();
private:
    QLineEdit *userNameLEd;      //用户名编辑行
    QLineEdit *pwdLEd;           //密码编辑行

    QPushButton *loginBtn;       //登录按钮
    QPushButton *exitBtn;        //退出按钮
    QPushButton *forgetPwdBtn;      //忘记密码
    QPushButton *registBtn;//注册账号

    Regedit *regedit;

    Forget *forget;
    Ui::LoginWindow *ui;

};
#endif // LOGINWINDOW_H
