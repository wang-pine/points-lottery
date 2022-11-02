#ifndef USERTAB_H
#define USERTAB_H

#include <QObject>
#include <QWidget>
#include <QList>

#include "jnavibutton.h"

namespace Ui {
class UserTab;
}
class UserTab : public QWidget
{
    Q_OBJECT
public:
    explicit UserTab(QWidget *parent = nullptr);
    void setTitleHeight(int height);
signals:
    void tab1_Clicked();
    void tab2_Clicked();
    void tab3_Clicked();
private:
    Ui::UserTab *ui;
    QList<JNaviButton*> m_listNaviButtons;
    int m_titleHeight;
};

#endif // USERTAB_H
