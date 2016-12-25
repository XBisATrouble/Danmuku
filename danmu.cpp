#include "Danmu.h"

Danmu::Danmu(QWidget * parent,QString text,QString color,int type,QFont danmuFont,double Transparency,int runTime):QLabel(parent){
    qDebug()<<"弹幕正在组装中!"<<endl;
    QDesktopWidget* desktopWidget;                                    //获取桌面设备
    QRect rect;
    desktopWidget = QApplication::desktop();                   //获取桌面设备
    rect = desktopWidget->screenGeometry();              //获取桌面大小的矩形
    this->screenrect=rect;
    this->DText=text;       //设置内容
    this->color=color;      //设置颜色
    this->type=type;        //设置类型
    this->danmuFont=danmuFont;      //弹幕字体
    this->Transparency=Transparency;        //弹幕透明度
    this->runTime=runTime;
    //this->screenrect=rect;
    QFontMetrics metrics(danmuFont);
    QPalette palll=QPalette();
    QString DColor = color;
    anim2 = NULL;
    //颜色字符串转化为特定的颜色
    //TODO:***改为switch****
    if(DColor == "White"){
        palll.setColor(QPalette::WindowText,QColor(255,255,246,255));
        this->qcolor=QColor(255,255,246,255);
    }else if(DColor =="Red"){
        palll.setColor(QPalette::WindowText,QColor(231,0,18,255));
        this->qcolor=QColor(231,0,18,255);
    }else if(DColor =="Yellow"){
        palll.setColor(QPalette::WindowText,QColor(254,241,2,255));
        this->qcolor=QColor(254,241,2,255);
    }else if(DColor == "Green"){
        palll.setColor(QPalette::WindowText,QColor(0,152,67,255));
        this->qcolor=QColor(0,152,67,255);
    }else if(DColor == "Blue"){
        palll.setColor(QPalette::WindowText,QColor(0,160,234,255));
        this->qcolor=QColor(0,160,234,255);
    }else if(DColor == "Pink"){
        palll.setColor(QPalette::WindowText,QColor(226,2,127,255));
        this->qcolor=QColor(226,2,127,255);
    }else if(DColor == "Grass"){
        palll.setColor(QPalette::WindowText,QColor(144,195,32,255));
        this->qcolor=QColor(144,195,32,255);
    }else if(DColor == "DBlue"){
        palll.setColor(QPalette::WindowText,QColor(0,46,114,255));
        this->qcolor=QColor(0,46,114,255);
    }else if(DColor == "DYellow"){
        palll.setColor(QPalette::WindowText,QColor(240,171,42,255));
        this->qcolor=QColor(240,171,42,255);
    }else if(DColor =="DPurple"){
        palll.setColor(QPalette::WindowText,QColor(104,58,123,255));
        this->qcolor=QColor(104,58,123,255);
    }else if(DColor == "LBlue"){
        palll.setColor(QPalette::WindowText,QColor(129,193,205,255));
        this->qcolor=QColor(129,193,205,255);
    }else if(DColor =="Brown"){
        palll.setColor(QPalette::WindowText,QColor(149,119,57,255));
        this->qcolor=QColor(149,119,57,255);
    }else{
        palll.setColor(QPalette::WindowText,QColor(255,255,246,255));
        this->qcolor=QColor(255,255,246,255);
    }
    this->setPalette(palll);        //设置调色盘
    this->setFixedHeight(metrics.height()+5);
    this->setFixedWidth(metrics.width(DText)+4);
    int yy = qrand()%rect.height();
    int y = yy<(rect.height()-metrics.height()-5)?(yy):(rect.height()-metrics.height()-5);
    int xx = rect.width()+qrand()%500;
    this->move(xx,y);
    this->PosX=xx;//设置弹幕水平的位置
    this->PosY=y;       //设置弹幕垂直位置

    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint);    //设置弹幕为无窗口无工具栏且呆在窗口顶端

    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setFocusPolicy(Qt::NoFocus);
    this->hide();
    anim2=new QPropertyAnimation(this, "pos");
    anim2->setDuration(this->runTime);
    anim2->setStartValue(QPoint(this->PosX,this->PosY));
    anim2->setEndValue(QPoint(-(this->width()), this->PosY));
    anim2->setEasingCurve(QEasingCurve::Linear);
    this->setWindowOpacity(this->Transparency);
    this->show();
    this->repaint();
}

void Danmu::paintEvent(QPaintEvent *){  //弹幕绘制函数
        QPainter painter(this);     //以弹幕窗口为画布
        painter.save();
        QFontMetrics metrics(this->danmuFont);     //获取弹幕字体
        QPainterPath path;      //描绘路径用
        QPen pen(QColor(0, 0, 0, 230));       //自定义画笔的样式，让文字周围有边框
        painter.setRenderHint(QPainter::Antialiasing);
        int penwidth = 4;
        pen.setWidth(penwidth);
        int len = metrics.width(DText);
        int w = this->width();
        int px = (len - w) / 2;
        if(px < 0)
        {
            px = -px;
        }
        int py = (height() - metrics.height()) / 2 + metrics.ascent();
        if(py < 0)
        {
            py = -py;
        }
        path.addText(px+2,py+2,this->danmuFont,DText);     //画字体轮廓
        painter.strokePath(path, pen);
        painter.drawPath(path);
        painter.fillPath(path, QBrush(this->qcolor));      //用画刷填充
        painter.restore();
}

Danmu::~Danmu(){
    qDebug()<<"弹幕已经被析构!"<<endl;
}

void Danmu::shootDanmu()
{
    anim2->start();
    qDebug()<<"弹幕已经发射!"<<endl;   
    connect(anim2,SIGNAL(finished()),this,SLOT(deleteLater()));   //监测弹幕是否应该被析构
}
