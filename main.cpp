#include "mainwindow.h"
#include "danmu.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QDesktopWidget* desktopWidget;                                    //获取桌面设备
    QRect screenRect;
    desktopWidget = QApplication::desktop();                   //获取桌面设备
    screenRect = desktopWidget->screenGeometry();              //获取桌面大小的矩形
    Danmu danmu(NULL,"hellow world!","White",1,screenRect);
    w.show();

    return a.exec();
}
