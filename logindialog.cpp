#include "logindialog.h"
#include "ui_logindialog.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setWindowFlags( Qt::FramelessWindowHint|Qt::WindowSystemMenuHint| Qt::WindowMinimizeButtonHint);//去掉默认系统标题栏
    initUI();
    this->setFixedSize(400,300);
}

void LoginDialog::initUI()
{
    ui->miniBtn->setCursor(QCursor(Qt::PointingHandCursor));
    ui->miniBtn->setStyleSheet(
    "QPushButton{border-image: url(://pic/miniBtn.png);}"
    "QPushButton:hover{border-image: url(://pic/miniBtn2.png);}"
    );

    ui->exitBtn2->setCursor(QCursor(Qt::PointingHandCursor));
    ui->exitBtn2->setStyleSheet(
    "QPushButton{border-image: url(://pic/closeBtn.png);}"
    "QPushButton:hover{border-image: url(://pic/closeBtn2.png);}"
    );

    ui->loginBtn->setCursor(QCursor(Qt::PointingHandCursor));

    ui->TID->setTextMargins(35,0,0,0);
    ui->TPWD->setTextMargins(35,0,0,0);

    ui->loginBtn->setStyleSheet(
    "QPushButton{border-image: url(://pic/button.png);}"
    "QPushButton:hover{border-image: url(://pic/button_hover.png);}"
    "QPushButton:pressed{border-image: url(://pic/button_press.png);}"
    );
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
    ui->TID->setFocus();
    QString TID=ui->TID->text().trimmed();
    QString TPWD=ui->TPWD->text().trimmed();

    //连接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("danmuku");
    db.setUserName("root");
    db.setPassword("root");
    if (!db.open())
        qDebug() << "Failed to connect to root mysql admin";
    else
        qDebug() << "open datebase successfully";

    QSqlQuery query;
    query.prepare("select count(*) from d_teacher where id=? and password=?");
    query.addBindValue(TID);
    query.addBindValue(TPWD);
    query.exec();
    query.next();


    if (query.value(0).toInt()==1){
        QSqlQuery query2;
        query2.prepare("select *from d_teacher where id=? and password=?");
        query2.addBindValue(TID);
        query2.addBindValue(TPWD);
        query2.exec();
        query2.next();
        name=query2.value(1).toString();
        accept();
    }else{
        QMessageBox::warning(this, tr("Waring"),tr("user name or password error!"),QMessageBox::Yes);
        ui->TID->clear();
        ui->TPWD->clear();
        ui->TID->setFocus();
    }
}
