//
// Created by ivan on 23.08.17.
//

#ifndef SECURECHAT_BACKEND_H
#define SECURECHAT_BACKEND_H

#include "CurrentUser.h"
#include "Dialog.h"
#include "Message.h"
#include "contactlist.h"

#include <QString>

#include <QAbstractListModel>
#include <QDebug>
#include <QtQml/QQmlListProperty>


class Backend : public QObject {
    Q_OBJECT
  public:
    Backend();
    ~Backend();

    bool authorize();
    void setUsername(const QString &username);
    QString getUsername();

    MessageList getMessages();
    void sendMessage(int dialogId, const QString &text);

    Q_INVOKABLE ContactModel* getContactList();

  signals:
    void messagesChanged();

  private:
    CurrentUser *currentUser;
};

#endif //SECURECHAT_BACKEND_H
