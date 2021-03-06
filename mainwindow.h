﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "danmu.h"
#include "titlewidget.h"
#include "messagewidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QMouseEvent>
#include <QMessageBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0,QString teacher_name=NULL);
    QString teacher_name;
    ~MainWindow();

private:
    void initUI();
    Ui::MainWindow *ui;
    TitleWidget *titleWidget;
    MessageWidget *messageWidget;
    QWidget *stateWidget;
    QPushButton *miniBut;
    QPushButton *closeBut;
    QPushButton *logoBut;
    QPushButton *registerBut;
    QPushButton *connect;
    QPushButton *disconnect;

    QPoint startPos;
    QPoint clickPos;
    bool isLeftPressDown;//判断是否左键按下   
    //bool isShowDanmu=true;
    QLabel *statusLabel;
    QLabel *infoLabel;



protected:
    //三个鼠标事件 按下 移动 释放
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void OpenDanmu();
    void CloseDanmu();
};

#endif // MAINWINDOW_H
