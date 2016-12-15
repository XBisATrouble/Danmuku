#include "mainwindow.h"
#include "echoclient.h"
#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    w.show();
    //EchoClient client(QUrl(QStringLiteral("ws://115.159.113.139:1997")), 1);
    //QObject::connect(&client, &EchoClient::closed, &a, &QCoreApplication::quit);
    return a.exec();
}
