#include "echoclient.h"
#include <QtCore/QDebug>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>
QT_USE_NAMESPACE

EchoClient::EchoClient(const QUrl &url, bool debug, QObject *parent) :
    QObject(parent),
    m_url(url),
    m_debug(debug)
{
    if (m_debug)
        qDebug() << "WebSocket server:" << url;
    connect(&m_webSocket, &QWebSocket::connected, this, &EchoClient::onConnected);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &EchoClient::closed);
    m_webSocket.open(QUrl(url));
}

void EchoClient::onConnected()
{
    if (m_debug)
        qDebug() << "WebSocket connected";
    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &EchoClient::onTextMessageReceived);

    QJsonObject json;
    json.insert("mode",QString("init"));
    json.insert("flag",QString("classroom"));
    json.insert("room",QString("2411"));

    QJsonDocument document;
    document.setObject(json);
    QByteArray byte_array=document.toJson(QJsonDocument::Compact);
    QString json_str(byte_array);

    m_webSocket.sendTextMessage(json_str);
}

void EchoClient::onTextMessageReceived(QString message)
{
    if (m_debug){
        Danmu *danmu=new Danmu(NULL,message,"white",1);
        qDebug() << "Message received:" << message;
        danmu->shootDanmu();  //调用shoot函数发射弹幕
    }

    //m_webSocket.close();
}
