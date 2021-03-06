﻿#include "mainwindow.h"
#include "ui_mainwindow.h"

bool isShowDanmu=true;

MainWindow::MainWindow(QWidget *parent,QString teacher_name) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->teacher_name=teacher_name;
    ui->setupUi(this);
    this->setFixedSize(800,500);
    setWindowFlags( Qt::FramelessWindowHint|Qt::WindowSystemMenuHint| Qt::WindowMinimizeButtonHint);//去掉默认系统标题栏
    //TODO
    initUI();
}

void MainWindow::initUI()
{
    QFont ft("Microsoft YaHei",16);

    //标题栏
    titleWidget = new TitleWidget(this);
    titleWidget->setFixedHeight(40);
    titleWidget->setFixedWidth(800);

    //最小化按钮
    miniBut=new QPushButton(this);
    miniBut->setFixedSize(30,30);
    miniBut->setCursor(QCursor(Qt::PointingHandCursor));
    //链接最小化事件
    QObject::connect(miniBut,SIGNAL(clicked(bool)),this,SLOT(showMinimized()));

    //关闭按钮
    closeBut=new QPushButton(this);
    closeBut->setFixedSize(30,30);
    closeBut->setCursor(QCursor(Qt::PointingHandCursor));
    //链接关闭槽函数
    QObject::connect(closeBut,SIGNAL(clicked(bool)),this,SLOT(close()));

    //logo图标
    logoBut=new QPushButton(this);
    logoBut->setFixedSize(376,34);

    //标题栏水平布局
    QHBoxLayout *titleLayout=new QHBoxLayout();
    titleLayout->addSpacing(5);
    titleLayout->addWidget(logoBut);
    titleLayout->addStretch(0);

    titleLayout->addWidget(miniBut);
    titleLayout->addWidget(closeBut);
    titleLayout->setSpacing(0);
    titleLayout->setMargin(2);
    titleWidget->setLayout(titleLayout);

    //信息栏
    messageWidget=new MessageWidget(this);
    messageWidget->setFixedSize(800,285);

    //签到按钮


    //信息栏水平布局
    QHBoxLayout *messageLayout=new QHBoxLayout();
    messageLayout->addStretch(0);
    messageLayout->setSpacing(0);
    messageWidget->setLayout(messageLayout);
    //TODO

    //链接按钮
    connect=new QPushButton(this);
    connect->setFixedSize(100,60);
    connect->setText(tr("开启弹幕"));
    disconnect=new QPushButton(this);
    disconnect->setFixedSize(100,60);
    disconnect->setText(tr("关闭弹幕"));
    QObject::connect(connect,SIGNAL(clicked(bool)),this,SLOT(OpenDanmu()));
    QObject::connect(disconnect,SIGNAL(clicked(bool)),this,SLOT(CloseDanmu()));

    QHBoxLayout *layoutBtn=new QHBoxLayout();
    layoutBtn->addWidget(connect);
    layoutBtn->addWidget(disconnect);

    statusLabel = new QLabel("         当前状态:已开启",this);
    statusLabel->setFont(ft);
    //垂直布局
    QVBoxLayout *layout1=new QVBoxLayout();
    layout1->addLayout(layoutBtn);
    layout1->addWidget(statusLabel);

    //分割线
    QLabel * fenge = new QLabel(this);
    QPixmap f;
    f.load(":/pic/fenge.png");        //加了条分隔线
    fenge->setPixmap(f);
    fenge->setFixedSize(f.size());

    //信息栏
    QString message("       欢迎您 ");
    message.append(teacher_name);
    message.append(" 老师，您当前的教室为:2410");
    infoLabel=new QLabel(message);
    infoLabel->setFont(ft);

    //状态栏
    stateWidget=new QWidget(this);
    stateWidget->setFixedSize(800,175);

    //状态栏水平布局
    QHBoxLayout *stateLayout=new QHBoxLayout();
    stateLayout->addLayout(layout1);
    stateLayout->addWidget(fenge);
    stateLayout->addWidget(infoLabel);
    stateLayout->setStretchFactor(layout1,3);
    stateLayout->setStretchFactor(fenge,1);
    stateLayout->setStretchFactor(infoLabel,6);
    stateWidget->setLayout(stateLayout);



    //整体布局
    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->addWidget(titleWidget);
    mainLayout->addWidget(messageWidget);
    mainLayout->addWidget(stateWidget);

    centralWidget()->setLayout(mainLayout);

    miniBut->setStyleSheet(
    "QPushButton{border-image: url(://pic/miniBtn.png);}"
    "QPushButton:hover{border-image: url(://pic/miniBtn2.png);}"
    );
    closeBut->setStyleSheet(
    "QPushButton{border-image: url(://pic/closeBtn.png);}"
    "QPushButton:hover{border-image: url(://pic/closeBtn2.png);}"
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button()&Qt::LeftButton){
        startPos=this->pos();
        clickPos=mapToGlobal(event->pos());
        isLeftPressDown=true;
        this->setFocus();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (this->isMaximized())
        return;
    if (isLeftPressDown)
        this->move(startPos+event->globalPos()-clickPos);
    event->accept();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    //鼠标施放
    repaint();
    if (event->button()==Qt::LeftButton){
        isLeftPressDown=false;
    }
}

void MainWindow::OpenDanmu()
{
    isShowDanmu=true;
    statusLabel->setText("         当前状态:已开启");
}

void MainWindow::CloseDanmu()
{
    isShowDanmu=false;
    statusLabel->setText("         当前状态:已关闭");
}
