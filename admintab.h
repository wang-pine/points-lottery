#ifndef ADMINTAB_H
#define ADMINTAB_H

#include <QWidget>
#include <QList>

#include "jnavibutton.h"

namespace Ui {
class AdminTab;
}
class AdminTab : public QWidget
{
    Q_OBJECT
public:
    explicit AdminTab(QWidget *parent = nullptr);

    void setTitleHeight(int height);

signals:
    void tab1_Clicked();
    void tab2_Clicked();
    void tab3_Clicked();

private:
    Ui::AdminTab *ui;
    QList<JNaviButton*> m_listNaviButtons;
    int m_titleHeight;
};

#endif // ADMINTAB_H
