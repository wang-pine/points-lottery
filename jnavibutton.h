#ifndef JNAVIBUTTON_H
#define JNAVIBUTTON_H

/** 功能
 * 1. 默认情况下，文字居中显示，不显示图标，不显示三角
 * 2. 可设置文字左侧、顶部、右侧、底部编剧；可设置文字显示对其方式
 * 3. 可设置图标是否显示、一侧边距、图标大小、显示位置
 * 4. 可设置三角是否显示、大小、显示位置，三角只设置了鼠标悬停和鼠标选中状态下显示
 * 5. 可设置北京颜色为画刷颜色
 * 6. 可设置文字与图标的相对位置：图标左文字右、图标右文字左、图标上文字下、图标下文字上
 * 7. 按钮状态分为三种：正常、鼠标悬停、鼠标选中
 * 8. 在按钮不同状态下可设置不同的背景颜色、字体颜色、图标切换、三角颜色等
 * 9. 一组导航按钮一次只能选中一个
 */

#include <QPushButton>
#include <QPainter>

class JNaviButton : public QPushButton
{
    Q_OBJECT
    Q_ENUMS(TextAlign)
    Q_ENUMS(IconPosition)

    Q_PROPERTY(int m_paddingLeft READ paddingLeft WRITE setPaddingLeft)
    Q_PROPERTY(int m_paddingTop READ paddingTop WRITE setPaddingTop)
    Q_PROPERTY(int m_paddingRight READ paddingRight WRITE setPaddingRight)
    Q_PROPERTY(int m_paddingBottom READ paddingBottom WRITE setPaddingBottom)
    Q_PROPERTY(TextAlign m_textAlign READ textAlign WRITE setTextAlign)
    Q_PROPERTY(QColor m_nTextColor READ normalTextColor WRITE setNormalTextColor)
    Q_PROPERTY(QColor m_hTextColor READ hoverTextColor WRITE setHoverTextColor)
    Q_PROPERTY(QColor m_cTextColor READ checkedTextColor WRITE setCheckedTextColor)
    Q_PROPERTY(QPen m_textPen READ textPen WRITE setTextPen)

    Q_PROPERTY(QBrush m_nBgBrush READ normalBgBrush WRITE setNormalBgBrush)
    Q_PROPERTY(QBrush m_hBgBrush READ hoverBgBrush WRITE setHoverBgBrush)
    Q_PROPERTY(QBrush m_cBgBrush READ checkedBgBrush WRITE setCheckedBgBrush)

    Q_PROPERTY(QColor m_nBgColor READ normalBgColor WRITE setNormalBgColor)
    Q_PROPERTY(QColor m_hBgColor READ hoverBgColor WRITE setHoverBgColor)
    Q_PROPERTY(QColor m_cBgColor READ checkedBgColor WRITE setCheckedBgColor)

    Q_PROPERTY(bool m_showIcon READ showIcon WRITE setShowIcon)
    Q_PROPERTY(int  m_iconSpace READ iconSpace WRITE setIconSpace)
    Q_PROPERTY(QSize m_iconSize READ iconSize WRITE setIconSize)
    Q_PROPERTY(QPixmap m_nIcon READ normalIcon WRITE setNormalIcon)
    Q_PROPERTY(QPixmap m_hIcon READ hoverIcon WRITE setHoverIcon)
    Q_PROPERTY(QPixmap m_cIcon READ checkedIcon WRITE setCheckedIcon)
    Q_PROPERTY(IconPosition m_iconPos READ iconPosition WRITE setIconPosition)

    Q_PROPERTY(bool m_showTriangle READ showTriabgle WRITE setShowTriangle)
    Q_PROPERTY(int m_triSideLength READ triangleSideLength WRITE setTriangleSideLength)
    Q_PROPERTY(TrianglePosition m_triPos READ trianglePos WRITE setTrianglePosition)
    Q_PROPERTY(QColor m_triColor READ triangleColor WRITE setTriangleColor)
public:
    explicit JNaviButton(QWidget *parent = 0);

    enum TextAlign {
        TextAlign_Left = 0x0001,        // 左对齐
        TextAlign_Right = 0x0002,       // 右对齐
        TextAlign_Top = 0x0020,         // 顶部对齐
        TextAlign_Bottom = 0x0040,      // 底部对齐
        TextAlign_Center = 0x0004       // 居中对齐
    };

    enum IconPosition {
        IP_Left = 0,                    // 左侧
        IP_Top = 1,                     // 顶部
        IP_Right = 2,                   // 右侧
        IP_Bottom = 3                   // 底部
    };

    enum TrianglePosition {
        TP_Left = 0,                    // 左侧
        TP_Top = 1,                     // 顶部
        TP_Right = 2,                   // 右侧
        TP_Bottom = 3                   // 底部
    };

protected:
    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);
    virtual void paintEvent(QPaintEvent *);

    void drawBackGround(QPainter *painter);
    void drawText(QPainter *painter);
    void drawIcon(QPainter *painter);
    void drawTriangle(QPainter *painter);

private:
    bool m_hover;                       // 鼠标悬停标志

    int m_paddingLeft;                  // 文字左侧间距
    int m_paddingTop;                   // 文字顶部间距
    int m_paddingRight;                 // 文字右侧间距
    int m_paddingBottom;                // 文字底部间距
    TextAlign m_textAlign;              // 文字对齐方式
    QColor m_nTextColor;                // 正常文字颜色
    QColor m_hTextColor;                // 悬停文字颜色
    QColor m_cTextColor;                // 选中文字颜色
    QPen m_textPen;                     // 文字大小、颜色

    QBrush m_nBgBrush;                  // 正常背景画刷
    QBrush m_hBgBrush;                  // 悬停背景画刷
    QBrush m_cBgBrush;                  // 选中背景画刷

    QColor m_nBgColor;                  // 正常背景颜色
    QColor m_hBgColor;                  // 悬停背景颜色
    QColor m_cBgColor;                  // 选中背景颜色

    bool m_showIcon;                    // 显示图标
    int m_iconSpace;                    // 图标边距，左边显示图标是距离左边边距，顶部显示图标表示距离顶部边距，以此类推
    QSize m_iconSize;                   // 图标尺寸
    QPixmap m_nIcon;                    // 正常图标
    QPixmap m_hIcon;                    // 悬停图标
    QPixmap m_cIcon;                    // 选中图标
    IconPosition m_iconPos;             // 图标显示位置

    bool m_showTriangle;                // 是否显示三角
    int m_triSideLength;                // 三角形边长
    TrianglePosition m_triPos;          // 三角形显示位置
    QColor m_triColor;                  // 三角形显示颜色

public:
    int paddingLeft() const;
    int paddingTop() const;
    int paddingRight() const;
    int paddingBottom() const;
    TextAlign textAlign() const;
    QColor normalTextColor() const;
    QColor hoverTextColor() const;
    QColor checkedTextColor() const;
    QPen textPen() const;

    QBrush normalBgBrush() const;
    QBrush hoverBgBrush() const;
    QBrush checkedBgBrush() const;

    QColor normalBgColor() const;
    QColor hoverBgColor() const;
    QColor checkedBgColor() const;

    bool showIcon() const;
    int iconSpace() const;
    QSize iconSize() const;
    QPixmap normalIcon() const;
    QPixmap hoverIcon() const;
    QPixmap checkedIcon() const;
    IconPosition iconPosition() const;

    bool showTriabgle() const;
    int triangleSideLength() const;
    TrianglePosition trianglePos() const;
    QColor triangleColor() const;

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

public Q_SLOTS:
    void setPaddingLeft(int padding);
    void setPaddingTop(int padding);
    void setPaddingRight(int padding);
    void setPaddingBottom(int padding);
    void setTextAlign(TextAlign align);
    void setNormalTextColor(const QColor &c);
    void setHoverTextColor(const QColor &c);
    void setCheckedTextColor(const QColor &c);
    void setTextPen(const QPen &pen);

    void setNormalBgBrush(const QBrush &b);
    void setHoverBgBrush(const QBrush &b);
    void setCheckedBgBrush(const QBrush &b);

    void setNormalBgColor(const QColor &c);
    void setHoverBgColor(const QColor &c);
    void setCheckedBgColor(const QColor &c);

    void setShowIcon(bool visible);
    void setIconSpace(int space);
    void setIconSize(int w, int h);
    void setIconSize(const QSize &size);
    void setNormalIcon(const QPixmap &nIcon);
    void setHoverIcon(const QPixmap &hIcon);
    void setCheckedIcon(const QPixmap &cIcon);
    void setIconPosition(IconPosition pos);

    void setShowTriangle(bool visiable);
    void setTriangleSideLength(int len);
    void setTrianglePosition(TrianglePosition pos);
    void setTriangleColor(const QColor &c);
};

#endif // JNAVIBUTTON_H
