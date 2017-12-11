#include "Firebase.h"

Firebase::Firebase(QString firebaseUrl) {
    m_firebaseUrl = firebaseUrl;
}

QString Firebase::getValue(QString endpoint) {
    return Request::get(m_firebaseUrl + endpoint + ".json");
}

void Firebase::listenForEvents() {
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QNetworkRequest request = QNetworkRequest(QUrl(m_firebaseUrl + ".json"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Accept", "text/event-stream");
    QNetworkReply *reply = manager->get(request);
    connect(reply, &QNetworkReply::readyRead, this, &Firebase::newEventCaptured);
}

void Firebase::newEventCaptured() {
    QNetworkReply *reply = (QNetworkReply *)sender();
    QString buffer = reply->readAll();
    FirebaseEvent e;
    qDebug() << "Firebase::newEventCaptured buffer" << buffer;
    e.type = (buffer.left(buffer.indexOf('\n'))).remove(0,7);
    e.data = buffer.right(buffer.size() - buffer.indexOf('\n') - 1);

    emit newEvent(e);
}
