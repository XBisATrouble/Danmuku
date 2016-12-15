#include "echoclient.h"
#include <QtCore/QDebug>

QT_USE_NAMESPACE

EchoClient::EchoClient(const QUrl &url, bool debug, QObject *parent) :
    QObject(parent),
    m_url(url),
    m_debug(debug)
{
    if (m_debug)
        qDebug() << "WebSocket server:" << url;
    //this->danmu=new Danmu(NULL,"text","White",1);
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
    m_webSocket.sendTextMessage(QStringLiteral("from QT5"));
}

void EchoClient::onTextMessageReceived(QString message)
{
    if (m_debug){
        Danmu *danmu=new Danmu(NULL,message,"white",1);
        qDebug() << "Message received:" << message;
        danmu->shootDanmu();
    }

    //m_webSocket.close();
}
