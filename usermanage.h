#ifndef USERMANAGE_H
#define USERMANAGE_H

#include <QWidget>
#include <QString>
namespace Ui {
class UserManage;
}
class UserManage :public QWidget
{
        Q_OBJECT
public:
    explicit UserManage(QWidget *parent = 0);
    QString getSearchValue();
    ~UserManage();
signals:
    void add_clicked();
    void save_clicked();
    void open_clicked();
    void search_clicked();
    void cover_clicked();
private:
    Ui::UserManage *ui;
};

#endif // USERMANAGE_H
