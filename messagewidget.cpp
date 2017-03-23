#include "messagewidget.h"
#include <QPainter>
#include <QPen>

MessageWidget::MessageWidget(QWidget *parent) : QWidget(parent)
{

}

void MessageWidget::paintEvent(QPaintEvent *)
{
    //this->setPaintStatus(0);
    //设置画笔
    QPen objPen(Qt::NoBrush,1);
    QPainter Painter(this);
    Painter.setPen(objPen);
    //设置渐变画刷
    QLinearGradient objLinear(rect().topLeft(),rect().bottomLeft());
    //顶部颜色和透明度
    objLinear.setColorAt(0,QColor(0,160,234,240));
    //中间颜色和透明度
    objLinear.setColorAt(0.9,QColor(51,122,183,255));
    //底部颜色和透明度
    objLinear.setColorAt(1,QColor(51,122,183,255));
    QBrush objBrush(objLinear);
    Painter.setBrush(objBrush);
    //画圆角矩形
    //Painter.drawRoundedRect(rect(),5,5);
    Painter.drawRect(rect());
}
