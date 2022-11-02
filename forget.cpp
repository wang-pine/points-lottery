#include "forget.h"

Forget::Forget(QWidget *parent):
    QWidget(parent)
{
    this -> resize(960,540);
    this -> setWindowTitle(tr("忘记密码"));
}
