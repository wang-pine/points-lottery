#include "jnavibutton.h"
#include <QDebug>


JNaviButton::JNaviButton(QWidget *parent)
    : QPushButton(parent)
    , m_hover(false)
    , m_paddingLeft(6)
    , m_paddingTop(2)
    , m_paddingRight(6)
    , m_paddingBottom(2)
    , m_textAlign(TextAlign_Center)
    , m_nTextColor(QColor(138, 43, 226))
    , m_hTextColor(QColor(255, 255, 255))
    , m_cTextColor(QColor(139, 69, 19))
    , m_nBgBrush(Qt::NoBrush)
    , m_hBgBrush(Qt::NoBrush)
    , m_cBgBrush(Qt::NoBrush)
    , m_nBgColor(QColor(205, 197, 191))
    , m_hBgColor(QColor(90, 165, 238))
    , m_cBgColor(QColor(173, 216, 234))
    , m_showIcon(false)
    , m_iconSpace(6)
    , m_iconSize(QSize(16, 16))
    , m_nIcon(QPixmap())
    , m_hIcon(QPixmap())
    , m_cIcon(QPixmap())
    , m_iconPos(IP_Left)
    , m_showTriangle(false)
    , m_triSideLength(5)
    , m_triPos(TP_Right)
    , m_triColor(QColor(255, 255, 255))
{
    // 设置按钮为可被选中
    setCheckable(true);
    // 一组按钮一次只能 选中一个
    setAutoExclusive(true);
}

void JNaviButton::enterEvent(QEvent *e)
{
    Q_UNUSED(e)
    m_hover = true;
}

void JNaviButton::leaveEvent(QEvent *e)
{
    Q_UNUSED(e)
    m_hover = false;
}

void JNaviButton::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    // 绘制背景
    drawBackGround(&painter);
    // 绘制文字
    drawText(&painter);
    // 绘制图标
    drawIcon(&painter);
    // 绘制三角
    drawTriangle(&painter);
}

void JNaviButton::drawBackGround(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    QBrush brush;
    if(isChecked()) {
        brush = m_cBgBrush;
    }
    else if(m_hover) {
        brush = m_hBgBrush;
    }
    else {
        brush = m_nBgBrush;
    }

    if(brush != Qt::NoBrush) {
        painter->setBrush(brush);
    }
    else {
        QColor color;
        if(isChecked()) {
            color = m_cBgColor;
        }
        else if(m_hover) {
            color = m_hBgColor;
        }
        else {
            color = m_nBgColor;
        }
        painter->setBrush(color);
    }

    QRect rect = QRect(0, 0, width(), height());
    painter->drawRect(rect);

    painter->restore();
}

void JNaviButton::drawText(QPainter *painter)
{
    painter->save();
    painter->setBrush(Qt::NoBrush);

    QColor color;
    if(isChecked()) {
        color = m_cTextColor;
    }
    else if(m_hover) {
        color = m_hTextColor;
    }
    else {
        color = m_nTextColor;
    }

    QRect rect = QRect(m_paddingLeft, m_paddingTop,
                       width() - m_paddingLeft - m_paddingRight,
                       height() - m_paddingTop - m_paddingBottom);
    m_textPen.setColor(color);
    painter->setPen(m_textPen);
    painter->drawText(rect, Qt::AlignVCenter | m_textAlign, text());
    painter->restore();
}

void JNaviButton::drawIcon(QPainter *painter)
{
    if(!m_showIcon) {
        return;
    }
    painter->save();
    QPixmap icon;
    if(isChecked()) {
        icon = m_cIcon;
    }
    else if(m_hover) {
        icon = m_hIcon;
    }
    else {
        icon = m_nIcon;
    }
    if(!icon.isNull()) {
        icon = icon.scaled(m_iconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        if(IP_Left == m_iconPos) {
            painter->drawPixmap(m_iconSpace, (height() - m_iconSize.height()) / 2, icon);
        }
        else if(IP_Top == m_iconPos) {
            painter->drawPixmap((width() - m_iconSize.width()) / 2, m_iconSpace, icon);
        }
        else if(IP_Right == m_iconPos) {
            painter->drawPixmap(width() - m_iconSize.width() - m_iconSpace,
                                (height() - m_iconSize.height()) / 2, icon);
        }
        else if(IP_Bottom == m_iconPos) {
            painter->drawPixmap((width() - m_iconSize.width()) / 2,
                                height() - m_iconSize.height() - m_iconSpace, icon);
        }
    }

    painter->restore();
}

void JNaviButton::drawTriangle(QPainter *painter)
{
    if(!m_showTriangle) {
        return;
    }
    if(!m_hover && !isChecked()) {
        return;
    }
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_triColor);
    QPolygon pts;
    if(TP_Left == m_triPos) {
        pts.setPoints(3, m_triSideLength, height() / 2,
                      0, height() / 2 - m_triSideLength,
                      0, height() / 2 + m_triSideLength);
    }
    else if(TP_Top == m_triPos) {
        pts.setPoints(3, width() / 2, m_triSideLength,
                      width() / 2 - m_triSideLength, 0,
                      width() / 2 + m_triSideLength, 0);
    }
    else if(TP_Right == m_triPos) {
        pts.setPoints(3, width() - m_triSideLength, height() / 2,
                      width(), height() / 2 - m_triSideLength,
                      width(), height() / 2 + m_triSideLength);
    }
    else if(TP_Bottom == m_triPos) {
        pts.setPoints(3, width() / 2, height() - m_triSideLength,
                      width() / 2 - m_triSideLength, height(),
                      width() / 2 + m_triSideLength, height());
    }
    painter->drawPolygon(pts);

    painter->restore();
}

int JNaviButton::paddingLeft() const
{
    return m_paddingLeft;
}

int JNaviButton::paddingTop() const
{
    return m_paddingTop;
}

int JNaviButton::paddingRight() const
{
    return m_paddingRight;
}

int JNaviButton::paddingBottom() const
{
    return m_paddingBottom;
}

JNaviButton::TextAlign JNaviButton::textAlign() const
{
    return m_textAlign;
}

QColor JNaviButton::normalTextColor() const
{
    return m_nTextColor;
}

QColor JNaviButton::hoverTextColor() const
{
    return m_hTextColor;
}

QColor JNaviButton::checkedTextColor() const
{
    return m_cTextColor;
}

QPen JNaviButton::textPen() const
{
    return m_textPen;
}

QBrush JNaviButton::normalBgBrush() const
{
    return m_nBgBrush;
}

QBrush JNaviButton::hoverBgBrush() const
{
    return m_hBgBrush;
}

QBrush JNaviButton::checkedBgBrush() const
{
    return m_cBgBrush;
}

QColor JNaviButton::normalBgColor() const
{
    return m_nBgColor;
}

QColor JNaviButton::hoverBgColor() const
{
    return m_hBgColor;
}

QColor JNaviButton::checkedBgColor() const
{
    return m_cBgColor;
}

bool JNaviButton::showIcon() const
{
    return m_showIcon;
}

int JNaviButton::iconSpace() const
{
    return m_iconSpace;
}

QSize JNaviButton::iconSize() const
{
    return m_iconSize;
}

QPixmap JNaviButton::normalIcon() const
{
    return m_nIcon;
}

QPixmap JNaviButton::hoverIcon() const
{
    return m_hIcon;
}

QPixmap JNaviButton::checkedIcon() const
{
    return m_cIcon;
}

JNaviButton::IconPosition JNaviButton::iconPosition() const
{
    return m_iconPos;
}

bool JNaviButton::showTriabgle() const
{
    return m_showTriangle;
}

int JNaviButton::triangleSideLength() const
{
    return m_triSideLength;
}

JNaviButton::TrianglePosition JNaviButton::trianglePos() const
{
    return m_triPos;
}

QColor JNaviButton::triangleColor() const
{
    return m_triColor;
}

QSize JNaviButton::sizeHint() const
{
    return QSize(100, 30);
}

QSize JNaviButton::minimumSizeHint() const
{
    return QSize(20, 10);
}

void JNaviButton::setPaddingLeft(int padding)
{
    if(m_paddingLeft != padding) {
        m_paddingLeft = padding;
        update();
    }
}

void JNaviButton::setPaddingTop(int padding)
{
    if(m_paddingTop != padding) {
        m_paddingTop = padding;
        update();
    }
}

void JNaviButton::setPaddingRight(int padding)
{
    if(m_paddingRight != padding) {
        m_paddingRight = padding;
        update();
    }
}

void JNaviButton::setPaddingBottom(int padding)
{
    if(m_paddingBottom != padding) {
        m_paddingBottom = padding;
        update();
    }
}

void JNaviButton::setTextAlign(TextAlign align)
{
    if(m_textAlign != align) {
        m_textAlign = align;
        update();
    }
}

void JNaviButton::setNormalTextColor(const QColor &c)
{
    if(m_nTextColor != c) {
        m_nTextColor = c;
        update();
    }
}

void JNaviButton::setHoverTextColor(const QColor &c)
{
    if(m_hTextColor != c) {
        m_hTextColor = c;
        update();
    }
}

void JNaviButton::setCheckedTextColor(const QColor &c)
{
    if(m_cTextColor != c) {
        m_cTextColor = c;
        update();
    }
}

void JNaviButton::setTextPen(const QPen &pen)
{
    if(m_textPen != pen) {
        m_textPen = pen;
        update();
    }
}

void JNaviButton::setNormalBgBrush(const QBrush &b)
{
    if(m_nBgBrush != b) {
        m_nBgBrush = b;
        update();
    }
}

void JNaviButton::setHoverBgBrush(const QBrush &b)
{
    if(m_hBgBrush != b) {
        m_hBgBrush = b;
        update();
    }
}

void JNaviButton::setCheckedBgBrush(const QBrush &b)
{
    if(m_cBgBrush != b) {
        m_cBgBrush = b;
        update();
    }
}

void JNaviButton::setNormalBgColor(const QColor &c)
{
    if(m_nTextColor != c) {
        m_nBgColor = c;
        update();
    }
}

void JNaviButton::setHoverBgColor(const QColor &c)
{
    if(m_hTextColor != c) {
        m_hBgColor = c;
        update();
    }
}

void JNaviButton::setCheckedBgColor(const QColor &c)
{
    if(m_cTextColor != c) {
        m_cBgColor = c;
        update();
    }
}

void JNaviButton::setShowIcon(bool visible)
{
    if(m_showIcon != visible) {
        m_showIcon = visible;
        update();
    }
}

void JNaviButton::setIconSpace(int space)
{
    if(m_iconSpace != space) {
        m_iconSpace = space;
        update();
    }
}

void JNaviButton::setIconSize(int w, int h)
{
    setIconSize(QSize(w, h));
}

void JNaviButton::setIconSize(const QSize &size)
{
    if(m_iconSize != size) {
        m_iconSize = size;
        update();
    }
}

void JNaviButton::setNormalIcon(const QPixmap &nIcon)
{
    if(nIcon.isNull())
        return;
    m_nIcon = nIcon;
    update();
}

void JNaviButton::setHoverIcon(const QPixmap &hIcon)
{
    if(hIcon.isNull())
        return;
    m_hIcon = hIcon;
    update();
}

void JNaviButton::setCheckedIcon(const QPixmap &cIcon)
{
    if(cIcon.isNull())
        return;
    m_cIcon = cIcon;
    update();
}

void JNaviButton::setIconPosition(IconPosition pos)
{
    if(m_iconPos != pos) {
        m_iconPos = pos;
        update();
    }
}

void JNaviButton::setShowTriangle(bool visiable)
{
    if(m_showTriangle != visiable) {
        m_showTriangle = visiable;
        update();
    }
}

void JNaviButton::setTriangleSideLength(int len)
{
    if(m_triSideLength != len) {
        m_triSideLength = len;
        update();
    }
}

void JNaviButton::setTrianglePosition(JNaviButton::TrianglePosition pos)
{
    if(m_triPos != pos) {
        m_triPos = pos;
        update();
    }
}

void JNaviButton::setTriangleColor(const QColor &c)
{
    if(m_triColor != c) {
        m_triColor = c;
        update();
    }
}
