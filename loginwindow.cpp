#include "loginwindow.h"
#include "adminmainwindow.h"
#include <QAction>
#include <QDebug>
#include "ui_loginwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QTextCodec>
#include <QByteArray>

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    //去掉标题

    //QSS加载
    QFile qss(":styleSheet.qss");
    if( qss.open(QFile::ReadOnly))
    {
        qDebug("open success");
        QString style = QLatin1String(qss.readAll());
        this->setStyleSheet(style);
        qss.close();
    }else{
        qDebug("Open failed");
    }

    setAttribute(Qt::WA_StyledBackground);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint); // 去掉标题栏,去掉任务栏显示，窗口置顶
    //设置窗体标题
    //this->setWindowTitle(tr("登录界面"));
    this->resize(600,337);

    //用户名输入框
    userNameLEd = new QLineEdit(this);
    userNameLEd->move(150,50);
    userNameLEd->setPlaceholderText(tr("请输入用户名!"));//占位符
    userNameLEd->setTextMargins(10,1,1,1);
    userNameLEd->setStyleSheet("#userNameLEd{qproperty-icon{image:url(:/Icon/myown.png);}}""#userNameLEd{qproperty-size:20px;}");
    QAction *userAction = new QAction(userNameLEd);
    userAction->setIcon(QIcon(":/Icon/myown.png"));
    userNameLEd->addAction(userAction,QLineEdit::LeadingPosition);
    //QLineEdit::LeadingPosition 在左侧,TrailingPosition在右侧
    userNameLEd ->setFocus();

    //密码输入框
    pwdLEd = new QLineEdit(this);
    pwdLEd -> move (150,130);
    pwdLEd -> setPlaceholderText(tr("请输入密码"));
    pwdLEd ->setTextMargins(10,1,1,1);
    pwdLEd->setStyleSheet("#pwdLEd{qproperty-icon{image:url(:/Icon/pwd.png);}}""#pwdLEd{qproperty-size:20px;}");
    QAction *pwdAction = new QAction(pwdLEd);
    pwdAction->setIcon(QIcon(":/Icon/pwd.png"));
    pwdLEd->addAction(pwdAction,QLineEdit::LeadingPosition);
    //QLineEdit::LeadingPosition 在左侧,TrailingPosition在右侧
    pwdLEd->setEchoMode(QLineEdit::Password);//输入的密码以圆点显示

    /*/////////////////////方便////////////////////*/
//        userNameLEd->setText("100015");
//        pwdLEd->setText("123123");


    //登录按钮
    loginBtn = new QPushButton(this);
    loginBtn -> move(250,210);
    loginBtn->setText(tr("登录"));
    connect(loginBtn,&QPushButton::clicked,this,&LoginWindow::login);

    //退出按钮
    exitBtn = new QPushButton(this);
    exitBtn->setIcon(QIcon(":/Icon/exit.png"));
    exitBtn->move(560,0);
    exitBtn -> setStyleSheet("QPushButton{border:none;background:transparent;}");
    exitBtn->resize(40,40);
    connect(exitBtn,&QPushButton::clicked,this,&LoginWindow::close);

    //注册按钮
    regedit = new Regedit;
    registBtn = new QPushButton(this);
    registBtn -> move(150,260);
    registBtn->setText(tr("注册"));
    connect(registBtn,&QPushButton::clicked,this,[=](){emit registersig();regJud = 1;login();});
    //忘记密码按钮
    forgetPwdBtn = new QPushButton(this);
    forgetPwdBtn -> move(350,260);
    forgetPwdBtn->setText(tr("忘记密码"));
    connect(forgetPwdBtn,&QPushButton::clicked,this,[=](){emit forgetSig();forgetJud = 1;login();});
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
void LoginWindow::login(){
    //获得userNameLEd输入框的文本：userNameLEd->text()；
    //trimmed()去掉前后空格
    //tr()函数，便于汉化
    this->loginJud = 0;
    qDebug() << "loginJud在loginWindow的cpp文件中的初始值" << this->loginJud << endl;
    if(userNameLEd->text().trimmed() == tr("admin") && pwdLEd->text() == tr("admin"))
    {
        accept();//关闭窗体，并设置返回值为Accepted
        this->loginJud = 1;
        qDebug() <<"loginWindow里面对loginJud赋初值"<< this->loginJud << endl;
    }
    //    else if(userNameLEd->text().trimmed() != tr("admin") || pwdLEd->text() != tr("admin"))
    //    {
    //        accept();//同上
    //        this->loginJud = 2;
    //        qDebug() <<"loginWindow里面对loginJud赋初值"<< this->loginJud << endl;
    //    }
    else if(regJud == 1){
        accept();
        this -> loginJud = 3;
        qDebug() << "loginWindow里面对loginJud赋初值"<< this->loginJud << endl;
        regJud = 0;
    }else if(forgetJud == 1){
        accept();
        this->loginJud = 4;
        qDebug() << "loginWindow里面对loginJud赋初值"<< this->loginJud << endl;
        forgetJud = 0;
    }
    else
    {
        QString userUID = this->userNameLEd->text().trimmed();
        qDebug() << "userUID是" << userUID;
        QString userPWD = this->pwdLEd->text().trimmed();
        QString adminUID;
        QString amdinPWD;
        QFile pwd(QDir::currentPath() + "/txt/userinfo.txt");
        pwd.open(QIODevice::ReadOnly|QIODevice::Text);
        qDebug() << "pwd读写";
        QByteArray arr;
        //QString arr;
        QTextCodec *tc = QTextCodec::codecForName("UTF-8");
        QString ptr;
        QString temp;
        while (!pwd.atEnd()) {
            arr = pwd.readLine();
            qDebug() << "当前的readline是" << arr;
            ptr = tc->toUnicode(arr);
            int len= arr.size();
            bool OK = false;
            for(int i = 0;i < len ;i ++){
                //-------------------文件扫描--------------------//
                //qDebug() << "密码文件读写开始";
                if(ptr[i]!='\t' && ptr[i] != '\n'){
                    temp.push_back(ptr[i]);
                }else{
                    qDebug() << temp;
                    if(temp == userUID){
                        qDebug() << "找到";
                        QByteArray arrTemp = arr;
                        qDebug() << "匹配行的内容是" << arrTemp;
                        int tempLen = arrTemp.size();
                        qDebug() << tempLen;
                        QTextCodec *tc2 = QTextCodec::codecForName("UTF-8");
                        QString pwdPtr;
                        pwdPtr = tc2->toUnicode(arrTemp);
                        int countT = 0;
                        QString tempPWD;
                        for(int i = 0;i < tempLen;i ++){
                            if(pwdPtr[i] != '\t'){
                                tempPWD.push_back(pwdPtr[i]);
                                qDebug() << "此时tempPWD的数值为"<< tempPWD;
                            }else{
                                countT ++;
                                if(countT == 2){
                                    qDebug()<< "匹配到的密码串为" << tempPWD;
                                    if(tempPWD == userPWD){
                                        qDebug() << "密码正确";
                                        accept();
                                        this->loginJud = 2;
                                        this->userJud = userUID;
                                        qDebug() << "userJud的数值为" << this->userJud;
                                        OK = true;
                                        break;
                                    }else{
                                        qDebug() << "密码错误";
                                        //标题              内容                OK按钮
                                        QMessageBox::warning(this, tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);
                                        // 清空输入框内容
                                        userNameLEd->clear();
                                        pwdLEd->clear();
                                    }
                                }
                                tempPWD = "";
                                //qDebug() << "countT的数值为";

                            }
                            if(OK) break;
                        }
                    }
                    if(OK) break;
                    qDebug() << "temp清空";
                    temp = "";
                }
                if(OK) break;
            }
        }
        //光标定位
        userNameLEd->setFocus();
    }
}
//void LoginWindow::registersig(){
//    qDebug() << "register is clicked" << endl;
//    //regJud = 1;
//}
//void LoginWindow::forgetSig(){
//    //forgetJud = 1;
//}
