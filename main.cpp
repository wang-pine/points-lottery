
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QDialog>
#include "adminmainwindow.h"
#include "usermainwindow.h"
#include "loginwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    LoginWindow login;
    login.show();
    Regedit *reg = new Regedit();
    Forget *forget = new Forget();
    if (login.exec() == QDialog::Accepted)//调用login.exec()，阻塞主控制流，直到完成返回，继续执行主控制流
    {
        //main->setWindowTitle("欢迎界面");//设置窗体标题
        qDebug()<< "login窗口对象里面loginJud接收到值"<< login.loginJud << endl;
       if(login.loginJud == 1){
           AdminMainWindow *adminwin = new AdminMainWindow();
           adminwin ->show();
           qDebug() << "admin" << endl;
       }else if(login.loginJud == 2){
           UserMainWindow *userwin = new UserMainWindow();
           userwin->setUid(login.userJud);
           userwin -> show();
           qDebug() << "user" << endl;
       }else if(login.loginJud == 3){
           reg -> show();
           qDebug() << "reg" << endl;
       }else if(login.loginJud == 4){
           forget->show();
           qDebug() << "forget" << endl;
       }
        return app.exec();
    }
    else return 0;
}

