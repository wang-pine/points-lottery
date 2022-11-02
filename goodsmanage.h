#ifndef GOODSMANAGE_H
#define GOODSMANAGE_H

#include <QWidget>
#include <QString>
namespace Ui {
class GoodsManage;
}

class GoodsManage:public QWidget
{
    Q_OBJECT
public:
    explicit GoodsManage(QWidget *parent = 0);
signals:
    void add_clicked();
    void open_clicked();
    void delete_clicked();
    void save_clicked();
private:
    Ui::GoodsManage *ui;
};

#endif // GOODSMANAGE_H
