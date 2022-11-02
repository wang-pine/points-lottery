#ifndef GAMBLEMANAGE_H
#define GAMBLEMANAGE_H
#include <QStandardItemModel>
#include <QTableView>
#include <QWidget>

namespace Ui {
class GambleManage;
}

class GambleManage:public QWidget
{
    Q_OBJECT
public:
    explicit GambleManage(QWidget *parent = 0);
    QStandardItemModel *histModel;
    QString getText();
    void setGambleModel(QStandardItemModel *model);
signals:
    void add_clicked();
    void delete_clicked();
    void save_clicked();
private:
    Ui::GambleManage *ui;
};

#endif // GAMBLEMANAGE_H
