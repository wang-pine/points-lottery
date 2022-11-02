#include "adminmainwindow.h"
#include "usermanage.h"
#include "goodsmanage.h"
#include "gamblemanage.h"

#include <iostream>
#include <QHeaderView>
#include <QString>
#include <QChar>
#include <QTextStream>
#include <QCheckBox>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QVector>
#include <QTextCodec>
#include <QMessageBox>
#include <QBrush>
#include <QAbstractScrollArea>
#include "QDebug"


AdminMainWindow::AdminMainWindow(QWidget *parent):
    QWidget(parent),
    ui_wSatckTabs(new QStackedWidget)
{
    this ->resize(960,540);
    //用户管理子页面
    //QTextCodec *codeC = QTextCodec::codecForName("GBK");
    //QTextCodec::setCodecForLocale(codeC);
    ui_user = new UserManage;
    ui_userWidget = new QTableView;//表格创建（可视）
    userModel = new QStandardItemModel();//表格模型（不可视）
    userModel->setColumnCount(6);
    userModel->setHorizontalHeaderLabels(QStringList() <<"check" << "ID" << "name" << "info" << "score" << "money");
    ui_userWidget->setModel(userModel);

    userSplitter = new QSplitter;
    userSplitter->addWidget(ui_user);
    userSplitter->addWidget(ui_userWidget);
    userSplitter->setStretchFactor(0,1);
    userSplitter->setStretchFactor(1,4);
    ui_wSatckTabs->addWidget(userSplitter);//在uStackTabs添加页面userSplitter

    //商品管理子页面
    ui_goods = new GoodsManage;
    ui_goodWidget = new QTableView;
    goodsModel = new QStandardItemModel();
    goodsModel->setColumnCount(5);
    goodsModel->setHorizontalHeaderLabels(QStringList() <<"check" << "ID" << "name" << "price" << "num");
    ui_goodWidget->setModel(goodsModel);

    goodSplitter= new QSplitter;
    goodSplitter->addWidget(ui_goods);
    goodSplitter->addWidget(ui_goodWidget);
    goodSplitter->setStretchFactor(0,1);
    goodSplitter->setStretchFactor(1,4);
    ui_wSatckTabs->addWidget(goodSplitter);

    //抽奖管理子页面
    ui_gamble = new GambleManage;
    ui_gambleWidget = new QTableView;
    prizeModel = new QStandardItemModel();
    prizeModel->setColumnCount(5);
    prizeModel->setHorizontalHeaderLabels(QStringList() << "check" << "ID" << "name" << "price" << "num");
    ui_gambleWidget->setModel(prizeModel);

    gambleModel = new QStandardItemModel();
    gambleModel->setColumnCount(3);
    gambleModel->setHorizontalHeaderLabels(QStringList() << "check" << "ID" << "info");
    ui_gamble->setGambleModel(gambleModel);
    gambleSplitter = new QSplitter;
    gambleSplitter->addWidget(ui_gamble);
    gambleSplitter->addWidget(ui_gambleWidget);
    gambleSplitter->setStretchFactor(0,1);
    gambleSplitter->setStretchFactor(1,4);
    ui_wSatckTabs->addWidget(gambleSplitter);

    //导航栏控件
    QVBoxLayout *ui_vLayWindow = new QVBoxLayout(this);
    AdminTab *ui_titleBar = new AdminTab(this);
    ui_titleBar ->setTitleHeight(50);
    ui_vLayWindow->addWidget(ui_titleBar);
    ui_vLayWindow->addWidget(ui_wSatckTabs);
    ui_vLayWindow->setMargin(0);
    setLayout(ui_vLayWindow);

    //信号之间的连接
    //导航栏信号
    connect(ui_titleBar,&AdminTab::tab1_Clicked,[=](){ui_wSatckTabs->setCurrentWidget(userSplitter);});
    connect(ui_titleBar,&AdminTab::tab2_Clicked,[=](){ui_wSatckTabs->setCurrentWidget(goodSplitter);});
    connect(ui_titleBar,&AdminTab::tab3_Clicked,[=](){ui_wSatckTabs->setCurrentWidget(gambleSplitter);});
    //按钮信号
    //user
    connect(ui_user,&UserManage::add_clicked,this,[=](){addUserTableRow();});
    connect(ui_user,&UserManage::save_clicked,this,[=](){saveUserTable();});
    connect(ui_user,&UserManage::open_clicked,this,[=](){openUserTable();});
    connect(ui_user,&UserManage::search_clicked,this,[=](){searchUserElem();});
    //goods
    connect(ui_goods,&GoodsManage::open_clicked,this,[=](){openGoodsTable();/*qDebug() << "goodsopen触发";*/});
    connect(ui_goods,&GoodsManage::add_clicked,this,[=](){addGoodsTableRow();});
    connect(ui_goods,&GoodsManage::save_clicked,this,[=](){saveGoodsTable();qDebug()<<"执行保存";});
    //gamble
    connect(ui_titleBar,&AdminTab::tab3_Clicked,this,[=](){openGambleInfo();});
    connect(ui_gamble,&GambleManage::add_clicked,this,[=](){addPrize();});
    connect(ui_gamble,&GambleManage::save_clicked,this,[=](){pushGamble();});
    connect(ui_gamble,&GambleManage::delete_clicked,this,[=](){delGambleInfo();});
}
/*User操作*/
void AdminMainWindow::openUserTable(){
    QString dir_str = QDir::currentPath() + "/txt";
    QDir dir;
    if(!dir.exists(dir_str)){
        bool res = dir.mkpath(dir_str);
        qDebug() << res << endl;
    }
    QFile temp_path(QDir::currentPath() + "/txt/user.txt");
    if(!dir.exists(QDir::currentPath() + "/txt/user.txt")){
        temp_path.open(QIODevice::ReadOnly | QIODevice::Text);
    }else{
        temp_path.open(QIODevice::ReadOnly|QIODevice::Text);
        int row = 0;        //表示user对象当前行数
        int column = 1;     //表示user对象当前列数
        QByteArray arr;
        //QString arr;
        QTextCodec *tc = QTextCodec::codecForName("UTF-8");
        while(!temp_path.atEnd()){
            arr = temp_path.readLine();
            qDebug() << arr;
            //char *ptr;
            int len;
            QString ptr;
            ptr = tc->toUnicode(arr);
            len = arr.size();

            QString temp_str;
            for(int i = 0;i < len;i ++){
                if(ptr[i] != '\t' && ptr[i] != '\n'){
                    //qDebug() << ptr[i] ;
                    temp_str.push_back(ptr[i]);
                }else{
                    qDebug() << temp_str;
                    qDebug() << "是";
                    //对userModel进行操作
                    userModel->setItem(row,column,new QStandardItem(temp_str));
                    qDebug() << "行" <<row <<"+" << "列"<< column;
                    column += 1;
                    temp_str = "";
                    if(column == 6){
                        qDebug() << "column == 6";
                        row ++;
                        column = 1;
                        qDebug() << "此时row的值为" << row;
                    }
                }
            }
        }
        userVaribleRows = userModel->rowCount();
        //获取当前行数
        qDebug() << "在open函数中variblerows的值是"<< userVaribleRows;
        temp_path.close();
    }
}

void AdminMainWindow::addUserTableRow(){
    userVaribleRows = userModel -> rowCount();
    qDebug() << "当前行数" << userVaribleRows << endl;
    QString a[4] = {"","","",""};
    for(int i = 0;i < 4;i ++){
        //        QStandardItem *check = new QStandardItem();
        //        check->setCheckable(true);
        //        check->setCheckState(Qt::Unchecked);
        //userModel->setItem(userVaribleRows,0,check);
        QString temp = QString::number(100001 + userVaribleRows);
        userModel->setItem(userVaribleRows,1,new QStandardItem(temp));
        userModel -> setItem(userVaribleRows,i+2,new QStandardItem(a[i]));
    }
    userVaribleRows += 1;
    userAddBtnCount ++;
}
void AdminMainWindow::saveUserTable(){
    for(int i = 0;i < userVaribleRows;i++){
        //qDebug() <<"当前第"<< i <<"行" << "第" << 0 << "列的效果" << userModel->item(i,0) -> checkState();
    }
    for(int i = 0;i < userVaribleRows;i ++){
        for(int j = 1;j < 6;j ++){
            qDebug() <<"当前第" << i <<"行 第"<< j << "列是否为空" << (userModel->item(i,j)->text().trimmed() == nullptr) <<endl;
            if(userModel->item(i,j)->text() == ""){
                QMessageBox::warning(this, tr("警告！"),tr("有空格，请填满所有空格"),QMessageBox::Yes);
                break;
            }
        }
    }
    QString dir_str = QDir::currentPath() + "/txt";
    QDir dir;
    if(!dir.exists(dir_str)){
        bool res = dir.mkpath(dir_str);
        qDebug() << res << endl;
    }
    QFile temp_path(QDir::currentPath() + "/txt/user.txt");
    if(!dir.exists(QDir::currentPath() + "/txt/user.txt")){
        temp_path.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream stream(&temp_path);
        //指定编码
        stream.setCodec("UTF-8");
        qDebug() << "文件的创建";
        temp_path.close();
    }else{
        temp_path.open(QIODevice::Append |QIODevice::Text);
        QTextStream stream(&temp_path);
        stream.setCodec("UTF-8");
        qDebug() << "在save函数中varivleRows的值2是" << userVaribleRows;
        qDebug() << "addCount的值是" << userAddBtnCount;
        for(int i = userVaribleRows-userAddBtnCount;i < userVaribleRows;i++){
            for(int j = 1;j < 6;j++){
                stream << userModel->item(i,j)->text().trimmed();
                if(j != 5) stream <<"\t";

            }
            stream << "\n";
        }
        temp_path.close();

        QFile temp2(QDir::currentPath() + "/txt/temp.txt");
        temp2.open(QIODevice::WriteOnly|QIODevice::Text);
        QTextStream in(&temp2);
        in.setCodec("UTF-8");
        for(int i = 0;i < userVaribleRows;i ++){
            for(int j = 1;j < 6; j ++){
                in << userModel->item(i,j)->text().trimmed();
                if(j != 5) in << "\t";
            }
            in << "\n";
        }
        temp2.close();

        QFile file1(QDir::currentPath() + "/txt/temp.txt");
        file1.rename(QDir::currentPath() + "/txt/user2.txt");
        file1.close();
        QFile file2(QDir::currentPath() + "/txt/user.txt");
        file2.rename(QDir::currentPath() + "/txt/temp.txt");
        file2.remove();
        QFile file3(QDir::currentPath() + "/txt/user2.txt");
        file3.rename(QDir::currentPath() + "/txt/user.txt");
        file3.close();
    }
}
void AdminMainWindow::searchUserElem(){
    qDebug() << "此时的admin主窗口中searchvalue的值是" << ui_user ->getSearchValue();
    QString needSearch = ui_user->getSearchValue();
    this->openUserTable();
    for(int i =0;i  <   userVaribleRows;i++)
    {
        for(int j = 1;j < 6;j ++)
        {
            if(userModel->item(i,j)->text().trimmed() == needSearch){
                qDebug() << "有";
                //.setSelectionBehavior(QAbstractItemView.SelectRows)
                userModel->item(i,j)->setForeground(QBrush(QColor(255,0,0)));
            }else{
                qDebug() << "无";
            }
        }
    }
}

/*goods操作*/
void AdminMainWindow::openGoodsTable(){
    qDebug()<<"openTable触发";
    QString dir_str = QDir::currentPath() + "/txt";
    qDebug() <<"currentpath" << dir_str;
    QDir dir;
    if(!dir.exists(dir_str)){
        bool res = dir.mkpath(dir_str);
        qDebug() << res << endl;
    }
    QFile temp_path(QDir::currentPath() + "/txt/goods.txt");
    if(!dir.exists(QDir::currentPath() + "/txt/goods.txt")){
        temp_path.open(QIODevice::ReadOnly | QIODevice::Text);
        qDebug() << "新文件";
        temp_path.close();
    }else{
        temp_path.open(QIODevice::ReadOnly|QIODevice::Text);
        qDebug() << "打开文件";
        int row = 0;        //表示user对象当前行数
        int column = 1;     //表示user对象当前列数
        QByteArray arr;
        QTextCodec *tc = QTextCodec::codecForName("UTF-8");
        //        QStandardItem *check = new QStandardItem();
        //        check->setCheckable(true);
        //        check->setCheckState(Qt::Unchecked);
        while(!temp_path.atEnd()){
            arr = temp_path.readLine();
            qDebug() << arr;
            int len;
            QString ptr;
            ptr = tc->toUnicode(arr);
            len = arr.size();
            QString temp_str;
            for(int i = 0;i < len;i ++){
                if(ptr[i] != '\t' && ptr[i] != '\n'){
                    //qDebug() << ptr[i] ;
                    temp_str.push_back(ptr[i]);
                }else{
                    qDebug() << temp_str;
                    qDebug() << "是";
                    //对goodsModel进行操作

                    goodsModel->setItem(row,column,new QStandardItem(temp_str));
                    //goodsModel->setItem(row,0,check);
                    qDebug() << "行" <<row <<"+" << "列"<< column;
                    column += 1;
                    temp_str = "";
                    if(column == 5){
                        qDebug() << "column == 5";
                        row ++;
                        column = 1;
                        qDebug() << "此时row的值为" << row;
                    }
                }
            }
        }
        goodsVaribleRows = goodsModel->rowCount();
        //获取当前行数
        qDebug() << "在goodsopen函数中variblerows的值是"<< goodsVaribleRows;
        temp_path.close();
    }
}
void AdminMainWindow::addGoodsTableRow(){
    goodsVaribleRows = goodsModel -> rowCount();
    qDebug() << "当前行数" << goodsVaribleRows << endl;
    qDebug() << "goodsBtn触发次数" <<goodsAddBtnCount << endl;
    //QStandardItem *check = new QStandardItem();
    //check->setCheckable(true);
    //check->setCheckState(Qt::Unchecked);
    //goodsModel->setItem(goodsVaribleRows,0,check);
    QString a[3] = {"","",""};
    for(int i = 0;i < 3;i ++){
        QString temp = QString::number(100001 + goodsVaribleRows);
        goodsModel->setItem(goodsVaribleRows,1,new QStandardItem(temp));
        goodsModel -> setItem(goodsVaribleRows,i+2,new QStandardItem(a[i]));
    }
    goodsVaribleRows += 1;
    goodsAddBtnCount ++;
}
void AdminMainWindow::saveGoodsTable(){
    //    goodsVaribleRows = goodsModel->columnCount();
    //    for(int i = 0;i < goodsVaribleRows;i++){
    //        //qDebug() <<"当前第"<< i <<"行" << "第" << 0 << "列的效果" << userModel->item(i,0) -> checkState();
    //    }
    //    for(int i = 0;i < goodsVaribleRows;i ++){
    //        for(int j = 1;j < 5;j ++){
    //            qDebug() <<"当前第" << i <<"行 第"<< j << "列是否为空" << (userModel->item(i,j)->text().trimmed() == nullptr) <<endl;
    //            if(goodsModel->item(i,j)->text() == ""){
    //                QMessageBox::warning(this, tr("警告！"),tr("有空格，请填满所有空格"),QMessageBox::Yes);
    //                break;
    //            }
    //        }
    //    }
    QString dir_str = QDir::currentPath() + "/txt";
    QDir dir;
    if(!dir.exists(dir_str)){
        bool res = dir.mkpath(dir_str);
        qDebug() << res << endl;
    }
    QFile temp_path(QDir::currentPath() + "/txt/goods.txt");
    if(!dir.exists(QDir::currentPath() + "/txt/goods.txt")){
        temp_path.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream stream(&temp_path);
        //指定编码
        stream.setCodec("UTF-8");
        qDebug() << "文件的创建";
        temp_path.close();
    }else{
        qDebug() <<"保存2admin";
        temp_path.open(QIODevice::Append |QIODevice::Text);
        QTextStream stream(&temp_path);
        stream.setCodec("UTF-8");
        qDebug() << "在save函数中varivleRows的值2是" << userVaribleRows;
        qDebug() << "addCount的值是" << goodsAddBtnCount;
        for(int i = goodsVaribleRows-goodsAddBtnCount;i < goodsVaribleRows;i++){
            for(int j = 1;j < 5;j++){
                stream << goodsModel->item(i,j)->text().trimmed();
                if(j != 4) stream <<"\t";
            }
            stream << "\n";
        }
        temp_path.close();

        QFile temp2(QDir::currentPath() + "/txt/temp1.txt");
        temp2.open(QIODevice::WriteOnly|QIODevice::Text);
        QTextStream in(&temp2);
        in.setCodec("UTF-8");
        for(int i = 0;i < goodsVaribleRows;i ++){
            for(int j = 1;j < 5; j ++){
                in << goodsModel->item(i,j)->text().trimmed();
                if(j != 4) in << "\t";
            }
            in << "\n";
        }
        temp2.close();

        QFile file1(QDir::currentPath() + "/txt/temp1.txt");
        file1.rename(QDir::currentPath() + "/txt/goods2.txt");
        file1.close();
        QFile file2(QDir::currentPath() + "/txt/goods.txt");
        file2.rename(QDir::currentPath() + "/txt/temp1.txt");
        file2.remove();
        QFile file3(QDir::currentPath() + "/txt/goods2.txt");
        file3.rename(QDir::currentPath() + "/txt/goods.txt");
        file3.close();
    }
}
void AdminMainWindow::openGambleInfo(){
    qDebug() <<"openGamble执行";
    qDebug()<<"openTable触发";
    //    QString dir_str = QDir::currentPath() + "/txt";
    //    qDebug() <<"currentpath" << dir_str;
    QDir dir;
    //    if(!dir.exists(dir_str)){
    //        bool res = dir.mkpath(dir_str);
    //        qDebug() << res << endl;
    //    }
    QFile temp_path(QDir::currentPath() + "/txt/goods.txt");
    if(!dir.exists(QDir::currentPath() + "/txt/goods.txt")){
        temp_path.open(QIODevice::ReadOnly | QIODevice::Text);
        qDebug() << "新文件";
        temp_path.close();
    }else{
        temp_path.open(QIODevice::ReadOnly|QIODevice::Text);
        qDebug() << "打开文件";
        int row = 0;        //表示user对象当前行数
        int column = 1;     //表示user对象当前列数
        QByteArray arr;
        QTextCodec *tc = QTextCodec::codecForName("UTF-8");
        while(!temp_path.atEnd()){
            arr = temp_path.readLine();
            qDebug() << arr;
            int len;
            QString ptr;
            ptr = tc->toUnicode(arr);
            len = arr.size();
            QString temp_str;
            for(int i = 0;i < len;i ++){
                if(ptr[i] != '\t' && ptr[i] != '\n'){
                    //qDebug() << ptr[i] ;
                    temp_str.push_back(ptr[i]);
                }else{
                    qDebug() << temp_str;
                    qDebug() << "是";
                    //对prizeModel进行操作
                    prizeModel->setItem(row,column,new QStandardItem(temp_str));
                    qDebug() << "行" <<row <<"+" << "列"<< column;
                    QStandardItem *check = new QStandardItem();
                    check->setCheckable(true);
                    check->setCheckState(Qt::Unchecked);
                    prizeModel->setItem(row,0,check);
                    column += 1;
                    temp_str = "";
                    if(column == 5){
                        qDebug() << "column == 5";
                        row ++;
                        column = 1;
                        qDebug() << "此时row的值为" << row;
                    }
                }
            }
        }
        //goodsVaribleRows = goodsModel->rowCount();
        //获取当前行数
        //qDebug() << "在goodsopen函数中variblerows的值是"<< goodsVaribleRows;
        temp_path.close();
    }

    //历史奖池列表设置
    QDir dir2;
    QFile path2(QDir::currentPath() + "/txt/gamble.txt");
    if(!dir.exists(QDir::currentPath() + "/txt/gamble.txt")){
        path2.open(QIODevice::ReadOnly |QIODevice::Text);
        path2.close();
    }else{
        path2.open(QIODevice::ReadOnly |QIODevice::Text);
        QByteArray tempArr;
        QTextCodec *tc = QTextCodec::codecForName("UTF-8");
        int row = 0;
        int column = 1;
        while(!path2.atEnd()){
            tempArr = path2.readLine();
            QString ptr2;
            ptr2 = tc->toUnicode(tempArr);
            int len2 = path2.size();
            QString temp_str2;
            for(int i = 0;i < len2; i++){
                if(ptr2[i] != '\t' && ptr2[i] != '\n'){
                    temp_str2.push_back(ptr2[i]);
                }else{
                    gambleModel->setItem(row,column,new QStandardItem(temp_str2));
                    QStandardItem *check = new QStandardItem;
                    check->setCheckable(true);
                    check->setCheckState(Qt::Unchecked);
                    gambleModel->setItem(row,0,check);
                    column ++;
                    qDebug() << "此时temp_str2" << temp_str2;
                    temp_str2 = "";
                    if(column == 3){
                        row ++;
                        column = 1;
                    }
                    //if(ptr2[i] == '\n'){

                    //}
                }
            }
        }
    }

}
void AdminMainWindow::addPrize(){
    qDebug() << "addPrize";
    int prizeRowCount = prizeModel->rowCount();
    qDebug() << prizeRowCount;
    int gambleRowCount = gambleModel->rowCount();
    histCount = gambleRowCount;

    QString Item;
    for(int i =0;i< prizeRowCount;i++){
        qDebug() << prizeModel->item(i,0)->checkState();
        if(prizeModel->item(i,0)->checkState() == Qt::Checked){
            qDebug() << prizeModel->item(i,1)->text().trimmed();
            qDebug() << "是被checked";
            //gambleModel->setItem();
            QString temp = prizeModel->item(i,1)->text().trimmed();
            Item.append(temp);
            Item.append(" ");
        }
    }
    qDebug() <<Item ;
    //gambleModel->setItem(histCount,1,new QStandardItem(prizeModel->));
    qDebug() << gambleRowCount;
    gambleModel->setItem(histCount,1,new QStandardItem(Item));
    QStandardItem *check = new QStandardItem();
    check->setCheckable(true);
    check->setCheckState(Qt::Unchecked);
    gambleModel->setItem(histCount,0,check);
}
void AdminMainWindow::delGambleInfo(){
    int gambleRowCount = gambleModel->rowCount();
    for(int i = 0;i < gambleRowCount; i ++){
        qDebug() << gambleModel->item(i,0)->checkState();
        if(gambleModel->item(i,0)->checkState() == Qt::Checked){
            qDebug() << i << "行是checked";
            //-----------------实现保存------------------------//
            QFile temp_path(QDir::currentPath() + "/txt/gamble1.txt");
            temp_path.open(QIODevice::WriteOnly|QIODevice::Text);
            QTextStream in(&temp_path);
            in.setCodec("UTF-8");
            for(int j =0;j< i;j++){
                for(int k = 1;k < 3;k ++){
                    in << gambleModel->item(j,k)->text();
                    if(k!=2)in << "\t";
                }
                in << "\n";
            }
            for(int j = i+1;j < gambleModel->rowCount();j ++){
                for(int k = 1;k < 3;k ++){
                    in << gambleModel->item(j,k)->text();
                    if(k!=2)in<< "\t";
                }
                in << "\n";
            }
            temp_path.close();
            QFile file1(QDir::currentPath() + "/txt/gamble.txt");
            if(file1.exists()){
                file1.remove();
                temp_path.rename(QDir::currentPath() + "/txt/gamble.txt");
            }else{
                temp_path.rename(QDir::currentPath() + "/txt/gamble.txt");
            }
            qDebug() << "执行到结尾";
            for(int i =0;i < gambleModel->rowCount();i ++){
                for(int j = 1;j < 3;j ++){
                    gambleModel->setItem(i,j,new QStandardItem(" "));
                }
            }
            ui_gamble->setGambleModel(gambleModel);
            openGambleInfo();
        }

    }
}

void AdminMainWindow::pushGamble(){
    qDebug() << "push gamble上线";
    qDebug() << ui_gamble->getText();
    QString temp;
    temp = ui_gamble->getText().trimmed();
    qDebug() << "histCount在push中的数值是" << histCount;
    gambleModel->setItem(histCount,2,new QStandardItem(temp));

    //本地文件的写入
    qDebug() << "文件写入执行";
    QString dir_str = QDir::currentPath() + "/txt";
    QDir dir;
    if(!dir.exists(dir_str)){
        bool res = dir.mkpath(dir_str);
        qDebug() << res << endl;
    }
    QFile temp_path(QDir::currentPath() + "/txt/gamble1.txt");
    if(!dir.exists(QDir::currentPath() + "/txt/gamble1.txt")){
        temp_path.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream stream(&temp_path);
        //指定编码
        stream.setCodec("UTF-8");
        qDebug() << "文件的创建";
        for(int i = 0;i < gambleModel->rowCount();i++){
            for(int j = 1;j < 3;j++){
                stream << gambleModel->item(i,j)->text();
                if(j != 2) stream <<"\t";
            }
            stream << "\n";
        }
        temp_path.close();
    }
    temp_path.close();
    QFile file1(QDir::currentPath() + "/txt/gamble.txt");
    if(file1.exists()){
        file1.remove();
        temp_path.rename(QDir::currentPath() + "/txt/gamble.txt");
    }else{
        temp_path.rename(QDir::currentPath() + "/txt/gamble.txt");
    }
    qDebug() << "执行到结尾";
}
