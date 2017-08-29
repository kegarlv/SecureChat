//
// Created by ivan on 23.08.17.
//

#ifndef SECURECHAT_BACKEND_H
#define SECURECHAT_BACKEND_H


#include "CurrentUser.h"
#include "Message.h"
#include "Dialog.h"

#include <QString>

#include <QDebug>
#include <QtQml/QQmlListProperty>

class Backend : public QObject {
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> messages READ getMessages NOTIFY messagesChanged)
public:

    Backend();
    ~Backend();

    bool authorize();
    void setUsername(const QString &username);
    QString username();
    Q_INVOKABLE void sendMessage(int dialogId, const QString &text);
    QList<QObject *> getMessages();
    Q_INVOKABLE QString me() {return "kegarlv";}
    Q_INVOKABLE QList<QObject *> getContactList();
    Q_INVOKABLE QList<QObject *> getMsg();

    signals:
    void messagesChanged();
private:
    CurrentUser *currentUser;

};


#endif //SECURECHAT_BACKEND_H
