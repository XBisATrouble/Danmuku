#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);
    setWindowFlags( Qt::FramelessWindowHint|Qt::WindowSystemMenuHint| Qt::WindowMinimizeButtonHint);//去掉默认系统标题栏
    //TODO
    initUI();

}

void MainWindow::initUI()
{
    titleWidget = new TitleWidget(this);
    titleWidget->setFixedHeight(40);
    titleWidget->setFixedWidth(900);

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(titleWidget);

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

    QHBoxLayout *titleLayout=new QHBoxLayout(); //标题栏水平布局
    titleLayout->addSpacing(5);
    titleLayout->addWidget(logoBut);
    titleLayout->addStretch(0);

    titleLayout->addWidget(miniBut);
    titleLayout->addWidget(closeBut);
    titleLayout->setSpacing(0);
    titleLayout->setMargin(2);
    titleWidget->setLayout(titleLayout);

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


