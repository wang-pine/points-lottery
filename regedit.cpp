#include "regedit.h"
#include <QVBoxLayout>
#include <QAction>
#include <QDebug>
#include <QPushButton>
#include <QDir>
#include <QFile>
#include <QPixmap>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QTextCodec>
#include <QMessageBox>
#include <QTextStream>

#include "ui_regedit.h"
Regedit::Regedit(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Regedit)
{
    this -> resize(600,900);
    this -> setWindowTitle(tr("账号注册"));
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

    //头像设置
    QPushButton *headBtn = new QPushButton(this);
    headBtn->setStyleSheet("#saveBtn{border-radius: 50px;}");
    QPixmap pic;
    pic.load(tr(":/Head/man1.png"));
    headBtn->setIcon(pic);
    headBtn->setIconSize(QSize(80,80));
    //saveBtn->setStyleSheet("#saveBtn{border-image:/Head/man1.png;}");
    headBtn->resize(100,100);
    headBtn->move(250,50);
    QWidget *headSelect = new QWidget;
    headSelect->setWindowTitle(tr("头像选择"));
    headSelect->resize(300,100);
    QPushButton *man1 = new QPushButton(headSelect);
    QPushButton *man2 = new QPushButton(headSelect);
    QPushButton *man3 = new QPushButton(headSelect);
    QPushButton *man4 = new QPushButton(headSelect);
    QPushButton *man5 = new QPushButton(headSelect);
    QPushButton *man6 = new QPushButton(headSelect);
    QPushButton *woman1 = new QPushButton(headSelect);
    QPushButton *woman2 = new QPushButton(headSelect);
    QPushButton *woman3 = new QPushButton(headSelect);
    QPushButton *woman4 = new QPushButton(headSelect);
    QPushButton *woman5 = new QPushButton(headSelect);
    QPushButton *woman6 = new QPushButton(headSelect);
    man1->resize(50,50);
    man2->resize(50,50);
    man3->resize(50,50);
    man4->resize(50,50);
    man5->resize(50,50);
    man6->resize(50,50);
    woman1->resize(50,50);
    woman2->resize(50,50);
    woman3->resize(50,50);
    woman4->resize(50,50);
    woman5->resize(50,50);
    woman6->resize(50,50);
    man1->move(0,0);
    man2->move(50,0);
    man3->move(100,0);
    man4->move(150,0);
    man5->move(200,0);
    man6->move(250,0);
    woman1->move(0,50);
    woman2->move(50,50);
    woman3->move(100,50);
    woman4->move(150,50);
    woman5->move(200,50);
    woman6->move(250,50);

    QPixmap pic1;
    pic1.load(tr(":/Head/man1.png"));
    man1->setIcon(pic1);
    man1->setIconSize(QSize(45,45));
    QPixmap pic2;
    pic2.load(tr(":/Head/man2.png"));
    man2->setIcon(pic2);
    man2->setIconSize(QSize(45,45));
    QPixmap pic3;
    pic3.load(tr(":/Head/man3.png"));
    man3->setIcon(pic3);
    man3->setIconSize(QSize(45,45));
    QPixmap pic4;
    pic4.load(tr(":/Head/man4.png"));
    man4->setIcon(pic4);
    man4->setIconSize(QSize(45,45));
    QPixmap pic5;
    pic5.load(tr(":/Head/man5.png"));
    man5->setIcon(pic5);
    man5->setIconSize(QSize(45,45));
    QPixmap pic6;
    pic6.load(tr(":/Head/man6.png"));
    man6->setIcon(pic6);
    man6->setIconSize(QSize(45,45));
    QPixmap pic7;
    pic7.load(tr(":/Head/woman1.png"));
    woman1->setIcon(pic7);
    woman1->setIconSize(QSize(45,45));
    QPixmap pic8;
    pic8.load(tr(":/Head/woman2.png"));
    woman2->setIcon(pic8);
    woman2->setIconSize(QSize(45,45));
    QPixmap pic9;
    pic9.load(tr(":/Head/woman3.png"));
    woman3->setIcon(pic9);
    woman3->setIconSize(QSize(45,45));
    QPixmap pic10;
    pic10.load(tr(":/Head/woman4.png"));
    woman4->setIcon(pic10);
    woman4->setIconSize(QSize(45,45));
    QPixmap pic11;
    pic11.load(tr(":/Head/woman5.png"));
    woman5->setIcon(pic11);
    woman5->setIconSize(QSize(45,45));
    QPixmap pic12;
    pic12.load(tr(":/Head/woman6.png"));
    woman6->setIcon(pic7);
    woman6->setIconSize(QSize(45,45));

    connect(headBtn,&QPushButton::clicked,headSelect,[=](){headSelect->show();});
    connect(man1,&QPushButton::clicked,this,[=](){headBtn->setIcon(pic1);headBtn->setIconSize(QSize(80,80));headID = 1;headSelect->close();});
    connect(man2,&QPushButton::clicked,this,[=](){headBtn->setIcon(pic2);headBtn->setIconSize(QSize(80,80));headID = 2;headSelect->close();});
    connect(man3,&QPushButton::clicked,this,[=](){headBtn->setIcon(pic3);headBtn->setIconSize(QSize(80,80));headID = 3;headSelect->close();});
    connect(man4,&QPushButton::clicked,this,[=](){headBtn->setIcon(pic4);headBtn->setIconSize(QSize(80,80));headID = 4;headSelect->close();});
    connect(man5,&QPushButton::clicked,this,[=](){headBtn->setIcon(pic5);headBtn->setIconSize(QSize(80,80));headID = 5;headSelect->close();});
    connect(man6,&QPushButton::clicked,this,[=](){headBtn->setIcon(pic6);headBtn->setIconSize(QSize(80,80));headID = 6;headSelect->close();});
    connect(woman1,&QPushButton::clicked,this,[=](){headBtn->setIcon(pic7);headBtn->setIconSize(QSize(80,80));headID = 7;headSelect->close();});
    connect(woman2,&QPushButton::clicked,this,[=](){headBtn->setIcon(pic8);headBtn->setIconSize(QSize(80,80));headID = 8;headSelect->close();});
    connect(woman3,&QPushButton::clicked,this,[=](){headBtn->setIcon(pic9);headBtn->setIconSize(QSize(80,80));headID = 9;headSelect->close();});
    connect(woman4,&QPushButton::clicked,this,[=](){headBtn->setIcon(pic10);headBtn->setIconSize(QSize(80,80));headID = 10;headSelect->close();});
    connect(woman5,&QPushButton::clicked,this,[=](){headBtn->setIcon(pic11);headBtn->setIconSize(QSize(80,80));headID = 11;headSelect->close();});
    connect(woman6,&QPushButton::clicked,this,[=](){headBtn->setIcon(pic12);headBtn->setIconSize(QSize(80,80));headID = 12;headSelect->close();});


    //账号注册栏
    nameLEd = new QLineEdit(this);
    nameLEd->move(150,200);
    nameLEd->setPlaceholderText(tr("你的名字"));
    QAction *nameAction = new QAction(nameLEd);
    nameAction->setIcon(QIcon(":/Icon/myown.png"));
    nameLEd->addAction(nameAction,QLineEdit::LeadingPosition);
    //QLineEdit::LeadingPosition 在左侧,TrailingPosition在右侧
    nameLEd ->setFocus();

    //密码注册栏
    pwdLEd = new QLineEdit(this);
    pwdLEd->move(150,300);
    pwdLEd->setPlaceholderText(tr("输入密码"));
    QAction *pwdAction = new QAction(pwdLEd);
    pwdAction->setIcon(QIcon(":/Icon/pwd.png"));
    pwdLEd->addAction(pwdAction,QLineEdit::LeadingPosition);

    //密码确认栏
    confirmLEd = new QLineEdit(this);
    confirmLEd->move(150,400);
    confirmLEd->setPlaceholderText(tr("确认密码"));
    QAction *confirmAction = new QAction(confirmLEd);
    confirmAction->setIcon(QIcon(":/Icon/pwd.png"));
    confirmLEd->addAction(confirmAction,QLineEdit::LeadingPosition);

    //UID信息提示
    QLabel *infoLbl = new QLabel(this);
    infoLbl->setText(tr("UID:"));
    infoLbl->move(240,500);


    //手机号确认栏
    phoneNumberLEd = new QLineEdit(this);
    phoneNumberLEd->move(150,550);
    phoneNumberLEd->setPlaceholderText(tr("手机号码"));
    QAction *phoneAction = new QAction(phoneNumberLEd);
    phoneAction->setIcon(QIcon(":/Icon/phone.png"));
    phoneNumberLEd->addAction(phoneAction,QLineEdit::LeadingPosition);

    //注册确认栏
    QPushButton *regeditBtn = new QPushButton(this);
    regeditBtn->setText(tr("注册"));
    regeditBtn->move(250,620);
    connect(regeditBtn,&QPushButton::clicked,this,[=](){regedit();});

    QString dir_str = QDir::currentPath() + "/txt";
    QDir dir;
    QFile userInfo_path(QDir::currentPath() + "/txt/userinfo.txt");
    QFile user_path(QDir::currentPath() + "/txt/user.txt");
    if(!dir.exists(QDir::currentPath() + "/txt/userinfo.txt")){
        userInfo_path.open(QIODevice::ReadOnly | QIODevice::Text);
        qDebug() << "生成在regedit";
        userInfo_path.close();
    }else{
        qDebug() << "open在regedit";
    }
    //userInfo_path.open(QIODevice::ReadOnly|QIODevice::Text);
    user_path.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextCodec *tc = QTextCodec::codecForName("UTF-8");
    QByteArray arr;
    while(!user_path.atEnd()){
        qDebug() << "在使用user.txt";
        arr = user_path.readLine();
        qDebug() << arr;
    }
    QString ptr;
    int len;
    ptr = tc->toUnicode(arr);
    len = arr.size();
    QString temp_str;
    for(int i = 0;i < len;i ++){
        if(ptr[i] != '\t'){
            temp_str.push_back(ptr[i]);
        }else{
            break;
        }
    }
    qDebug() << temp_str;
    int temp_int = temp_str.toInt();
    temp_int ++;
    qDebug() << temp_int;
    UID = QString::number(temp_int);
    user_path.close();
    userInfo_path.close();

    QLabel *idLbl = new QLabel(this);
    idLbl -> setText(UID);
    idLbl->move(290,500);


}
void Regedit::regedit(){
    qDebug() << "注册开始";
    if(pwdLEd->text().trimmed() != confirmLEd->text().trimmed()){
        QMessageBox::warning(this, tr("警告！"),tr("密码和确认密码不匹配！"),QMessageBox::Yes);
        pwdLEd->clear();
        confirmLEd->clear();
    }
    if(nameLEd->text().isEmpty()){
        QMessageBox::warning(this,tr("警告！"),tr("请输入用户名！"),QMessageBox::Yes);
    }
    if(pwdLEd->text().isEmpty()){
        QMessageBox::warning(this,tr("警告！"),tr("密码为空！"),QMessageBox::Yes);
    }
    if(confirmLEd->text().isEmpty()){
        QMessageBox::warning(this,tr("警告！"),tr("确认密码为空！"),QMessageBox::Yes);
    }
    if(phoneNumberLEd->text().isEmpty()){
        QMessageBox::warning(this,tr("警告！"),tr("手机号码为空！"),QMessageBox::Yes);
    }
    if(pwdLEd->text().trimmed() == confirmLEd->text().trimmed() && ! nameLEd->text().isEmpty() && !pwdLEd->text().isEmpty() && !confirmLEd->text().isEmpty() && !phoneNumberLEd->text().isEmpty()){
        qDebug() << "注册成功";

        QFile pwd(QDir::currentPath() + "/txt/userinfo.txt");
        pwd.open(QIODevice::Append|QIODevice::Text);
        QTextStream in(&pwd);
        in.setCodec("UTF-8");
        in << UID << "\t" << pwdLEd->text().trimmed() << '\t' << headID<< "\t" << phoneNumberLEd->text() << "\n";
        pwd.close();
        QFile user(QDir::currentPath() + "/txt/user.txt");
        user.open(QIODevice::Append | QIODevice::Text);
        QTextStream in2(&user);
        in2.setCodec("UTF-8");
        in2 << UID << "\t" << nameLEd->text().trimmed() << "\t" << "0" << "\t" << "0" << "\t" << "0" << "\n";
        user.close();
        QMessageBox::warning(this,tr("注意！"),tr("注册成功！请返回登录窗口！"),QMessageBox::Yes);
    }
}
