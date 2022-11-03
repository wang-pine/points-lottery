#include "usermainwindow.h"
#include <QHeaderView>
#include <QString>
#include <QFile>
#include <QDir>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QTextCodec>
#include <QTimer>
#include <QMessageBox>
#include <QButtonGroup>

#include "gamble.h"
#include "addone.h"
#include "QDebug"
#include "usertab.h"
//def printf(self, mes):


UserMainWindow::UserMainWindow(QWidget *parnet):
    QWidget(parnet),
    ui_wSatckTabs(new QStackedWidget)
{
    this -> resize(960,540);

    setAttribute(Qt::WA_StyledBackground);

    UserTab *ui_tab = new UserTab(this);
    ui_tab->setTitleHeight(50);
    ui_info = new UserInfo(this);
    ui_info2 = new UserInfo(this);

    ui_buy = new QTextBrowser(this);
    ui_gamble = new QTableView(this);
    gambleModel = new QStandardItemModel();
    gambleModel->setColumnCount(3);
    gambleModel->setHorizontalHeaderLabels(QStringList() << "check" << "prize" << "info");
    ui_gamble->setModel(gambleModel);
    QPushButton *btnONE = new QPushButton();
    btnONE->setText("单抽");
    buySplitter = new QSplitter;
    buySplitter->addWidget(ui_info2);
    buySplitter->addWidget(ui_buy);
    buySplitter->setStretchFactor(0,1);
    buySplitter->setStretchFactor(1,4);
    ui_wSatckTabs->addWidget(buySplitter);

    gambleSplitter = new QSplitter;
    gambleSplitter->addWidget(ui_info);
    gambleSplitter->addWidget(ui_gamble);
    gambleSplitter->setStretchFactor(0,1);
    gambleSplitter->setStretchFactor(1,4);
    ui_wSatckTabs->addWidget(gambleSplitter);

    QVBoxLayout *ui_vLayWindow = new QVBoxLayout(this);
    ui_vLayWindow->addWidget(ui_tab);
    ui_vLayWindow->addWidget(ui_wSatckTabs);
    ui_vLayWindow->setMargin(0);
    setLayout(ui_vLayWindow);
    connect(ui_tab,&UserTab::tab1_Clicked,[=](){ui_wSatckTabs->setCurrentWidget(buySplitter);});
    connect(ui_tab,&UserTab::tab2_Clicked,[=]{
        ui_wSatckTabs->setCurrentWidget(gambleSplitter);
        ui_info->addBrowserClik();
        ui_info->addBtnClik();
        ui_info->addTENBtnClik();
        openGamble();});
    connect(ui_info,&UserInfo::addONE_clicked,[=](){
        priz = gambONE(UID);
        ui_info->print(priz,score_str);
    });
}
void UserMainWindow::setUid(QString id){
    this->UID=id;
    ui_info->setID(id);
    ui_info2->setID(id);
    qDebug() << "在usermainwindow中UID是" << this->UID;
    QFile info(QDir::currentPath() + "/txt/userinfo.txt");
    info.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray arr;
    QTextCodec *tc = QTextCodec::codecForName("UTF-8");
    bool OK = false;
    QString head;
    QString phone;
    while(!info.atEnd()){
        if(OK) break;
        arr = info.readLine();
        qDebug() << arr;
        QString ptr;
        ptr = tc->toUnicode(arr);
        int len = arr.size();
        QString temp_str;
        int countT = 0;
        for(int i = 0;i < len;i ++){
            if(ptr[i] != '\t' && ptr[i] != '\n'){
                temp_str.push_back(ptr[i]);
                //qDebug() << temp_str;
            }else{
                countT ++;
                if(countT == 3){head = temp_str;qDebug() << "head" << head;ui_info->setHead(head);ui_info2->setHead(head);}
                if(countT == 4){phone = temp_str;qDebug() << "phone"<< phone;}
                if(temp_str == UID){
                    qDebug() << "捕捉到uid" << UID;
                    OK = true;
                }
                temp_str = "";
            }
        }
    }
    info.close();
    QString name;
    QString score;
    QString money;

    QFile info2(QDir::currentPath() + "/txt/user.txt");
    info2.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray arr2;
    QTextCodec *tc2 = QTextCodec::codecForName("UTF-8");
    bool OK2 = false;
    while(!info2.atEnd()){
        if(OK2)break;
        arr2 = info2.readLine();
        QString ptr2;
        ptr2 = tc2->toUnicode(arr2);
        int len2 = arr2.size();
        QString temp2;
        int countT = 0;
        for(int i = 0;i < len2;i ++){
            if(ptr2[i] != '\t' && ptr2[i] !='\n'){
                temp2.push_back(ptr2[i]);
            }else{
                qDebug() << temp2;
                if(countT > 0){
                    if(countT == 1){name = temp2;qDebug() << "name" << name;ui_info->setName(name);ui_info2->setName(name);};
                    if(countT == 3){score = temp2;qDebug() << "score" << score;score_str = score;ui_info->setScore(score);ui_info2->setScore(score);};
                    if(countT == 4){money = temp2;ui_info->setMoney(money);ui_info2->setMoney(money);countT = -1;};
                }
                if(countT > 0)countT ++;
                if(temp2 == UID){
                    qDebug() << "捕捉到uid" << UID;
                    OK = true;
                    countT ++;
                }
                temp2 = "";
            }
        }
    }
    qDebug() << "在主窗口中此时的用户数据" << UID << ":" << name << ":" << score <<  ":" << money;
    info2.close();

}
QString UserMainWindow::gambONE(QString id){
    if(score_str.toInt() < 160){
        QMessageBox *box = new QMessageBox;
        QPushButton *btn = new QPushButton(QString::fromLocal8Bit("yes"));
        box->setIcon(QMessageBox::Warning);
        box->addButton(btn,QMessageBox::AcceptRole);
        box->setText(tr("警告！")+tr("积分显然不足！"));
        //QMessageBox::warning(this, tr("警告！"),tr("积分显然不足"),QMessageBox::Yes);
        box->exec();
        if(box->clickedButton() == btn){
            box->close();
        }
    }else{
        addONE add(id);
        /*通过扫描复选框来判定需要选择的*/
        int row = gambleModel->rowCount();
        int column = gambleModel->columnCount();
        int checkedCount = 0;
        QString check_str;
        for(int i = 0;i < row;i++){
            qDebug() <<"在第" << i << "行的checkState为" << gambleModel->item(i,0)->checkState();
            if(gambleModel->item(i,0)->checkState() == Qt::Checked){
                checkedCount ++;
                check_str = gambleModel->item(i,1)->text().trimmed();

            }
        }
        if(checkedCount > 1){
            QMessageBox::warning(this, tr("警告！"),tr("一次仅仅可以选择一个奖池进行抽奖！"),QMessageBox::Yes);
        }else if(checkedCount == 0){
            QMessageBox::warning(this, tr("警告！"),tr("请选择目标奖池进行抽奖！"),QMessageBox::Yes);
        }else{
            qDebug() << "checked的内容是" << check_str;
            first_prize_str = check_str;
            if(first_prize_num == 0){
                add.gambONE("100001");
            }else{
                add.gambONE(first_prize_str);//设置一等奖的字符串                
            }

            if(!JUD){
            first_prize_num = add.return_num;
            JUD = true;
            }
            qDebug() << "函数被调用";
            int temp1 = score_str.toInt() - 160;
            QString temp2 = QString::number(temp1);
            ui_info->setScore(temp2);
            score_str = temp2;
            //ui_info->repaint();

            if(add.prize_get == first_prize_str){
                first_prize_num --;
            }
            return add.prize_get;
        }
    }
}
void UserMainWindow::openGamble(){
    QFile temp(QDir::currentPath() + "/txt/gamble.txt");
    temp.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray arr;
    QTextCodec *tc = QTextCodec::codecForName("UTF-8");
    int countColumn = 1;
    int countRow = 0;
    //QButtonGroup *group = new QButtonGroup(this);
    while(!temp.atEnd()){
        arr = temp.readLine();
        QString ptr = tc->toUnicode(arr);
        int len = arr.size();
        QString temp_str;
        for(int i = 0;i < len ;i ++){
            if(ptr[i] != '\t' && ptr[i] != '\n'){
                //qDebug() << ptr[i] ;
                temp_str.push_back(ptr[i]);
            }else{
                gambleModel->setItem(countRow,countColumn,new QStandardItem(temp_str));
                QStandardItem *check = new QStandardItem;
                check->setCheckable(true);
                check->setCheckState(Qt::Unchecked);
                //group ->addButton(check);
                gambleModel->setItem(countRow,0,check);
                countColumn ++;
                if(countColumn == 3){
                    countColumn = 1;
                    countRow ++;
                }
                temp_str = "";
            }
        }
    }
    temp.close();
}
