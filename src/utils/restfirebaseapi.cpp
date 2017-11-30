#include "restfirebaseapi.h"

RestFirebaseAPI::~RestFirebaseAPI() {}

QJsonArray RestFirebaseAPI::getContactList(const QString &username) {
    QString response = Request::get(USER_URL + username + "/contactList.json");
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(response.toUtf8(), &err);
    QJsonArray obj = doc.array();
    return obj;
}

void RestFirebaseAPI::sendMessage(const int dialogId, const Message &message) {
    QString requestUrl = DIALOG_URL + QString::number(dialogId) + "/messages.json";
    Request::post(requestUrl, message.toJson());
}

QJsonObject RestFirebaseAPI::getMessages(const int dialogId) {
    QString requestString = DIALOG_URL + QString::number(dialogId) + QString::fromStdString("/messages.json");
    qDebug() << requestString;
    QString response = Request::get(requestString);
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(response.toUtf8(), &err);
    QJsonObject obj = doc.object();
    return obj;
}

QImage RestFirebaseAPI::getAvatar(const QString &username)
{
    //TODO enable cache
    QString response = Request::get(USER_URL + username + "/avatar.json");
    QDataStream dataStream(response.toUtf8());
    QImage img;
    dataStream >> img;
    return img;
}
