//
// Created by ivan on 23.08.17.
//

#ifndef SECURECHAT_BACKEND_H
#define SECURECHAT_BACKEND_H

#include "CurrentUser.h"
#include "Dialog.h"

#include "models/messagelist.h"
#include "models/contactlist.h"

#include <QString>

#include <QAbstractListModel>
#include <QDebug>
#include <QtQml/QQmlListProperty>


class Backend : public QObject {
    Q_OBJECT
  public:
    Backend(const QString &username);
    ~Backend();

    bool authorize();
    Q_INVOKABLE QString getUsername();

    Q_INVOKABLE ContactModel* getContactList();
    Q_INVOKABLE MessageList* getMessages(int dialogId);
    Q_INVOKABLE void sendMessage(int dialogId, const QString &text);
  signals:
    void messagesChanged();

  private:
    CurrentUser *currentUser;
};

#endif //SECURECHAT_BACKEND_H
