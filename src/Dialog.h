//
// Created by ivan on 22.08.17.
//

#ifndef SECURECHAT_DIALOG_H
#define SECURECHAT_DIALOG_H

#include "CurrentUser.h"
#include "Message.h"

#include "../libs/restclient-cpp/restclient.h"
#include "../libs/restclient-cpp/helpers.h"

#include "../libs/json.h"

#include <QList>
#include <QVariant>
#include <thread>
#include <unistd.h>

class Dialog {

public:
    explicit Dialog(CurrentUser &currentUser, int dialogId);

    QList<QObject*> dumpMessages();
    void writeMessage(QString);

private:
    CurrentUser &currentUser;
    int dialogId;

    QString dialogName;
    const QString DIALOG_URL = "https://securechat-4276e.firebaseio.com/Dialogs/";

    QList<QObject*> m_messages;

};


#endif //SECURECHAT_DIALOG_H
