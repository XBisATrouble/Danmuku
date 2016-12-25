#pragma once
#pragma execution_character_set("utf-8")

#include <QLabel>
#include <QRect>
#include <QColor>
#include <QDebug>
#include <QTextCharFormat>
#include <QPainter>
#include <iostream>
#include <QTime>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QDesktopWidget>
#include <QApplication>
enum{red=1,blue,green,white,black};
class Danmu : public QLabel{

    Q_OBJECT

  public:

      Danmu(QWidget * parent,QString text,QString color,int type,QFont danmuFont = QFont("SimHei",20,100),double Transparency = 1.00,int runTime=15000);       //构造函数

      void shootDanmu();

      ~Danmu();     //析构函数

  protected:
      void paintEvent(QPaintEvent *);       //重点，弹幕的绘制函数

  private:
      int PosX;
      int PosY;
      QString DText;
      QString color;
      QColor qcolor;
      int type;
      QFont danmuFont;
      int DHeight;
      double Transparency;
      QRect screenrect;
      QPropertyAnimation *anim2;
      int runTime;
};
