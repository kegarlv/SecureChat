#ifndef FIREBASEAPI_H
#define FIREBASEAPI_H

#include "src/structs/Message.h"
#include <QJsonArray>
#include <QString>
#include <QImage>


class FirebaseAPI {
  public:
    FirebaseAPI() = default;
    virtual ~FirebaseAPI() = 0;

    virtual QJsonArray getContactList(const QString &username) = 0;
    virtual void sendMessage(const int dialogId, const Message &message) = 0;
    virtual QJsonObject getMessages(const int dialogId, const int startPosition = 0) = 0;

    virtual QImage getAvatar(const QString &username);
};

#endif // FIREBASEAPI_H
