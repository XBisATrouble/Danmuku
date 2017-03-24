#include "logindialog.h"
#include "ui_logindialog.h"
#include <QSqlDatabase>
#include <QDebug>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setFixedSize(400,300);
}

void LoginDialog::initUI()
{

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
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


    accept();
}
