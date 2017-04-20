#include "mainwindow.h"
#include "echoclient.h"
#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>
#include "logindialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog login;
    //EchoClient client(QUrl(QStringLiteral("ws://115.159.113.139:1997")), 1);          //本地0.0.0.0
    //QObject::connect(&client, &EchoClient::closed, &a, &QCoreApplication::quit);
    if (login.exec() == QDialog::Accepted)
    {
        MainWindow w(NULL,login.name);
        w.show();
        return a.exec();
    }
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    //w.show();
    return a.exec();
}
