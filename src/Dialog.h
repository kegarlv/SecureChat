//
// Created by ivan on 22.08.17.
//

#ifndef SECURECHAT_DIALOG_H
#define SECURECHAT_DIALOG_H

#include "../libs/json.h"

#include <QList>
#include <QVariant>
#include <unistd.h>

#include <QDebug>

#include "CurrentUser.h"
#include "Message.h"
#include "request.h"
#include "messagelist.h"

class Dialog {

public:
    explicit Dialog(int dialogId);

    MessageList dumpMessages();
    void writeMessage(QString);

private:
    CurrentUser *currentUser;
    int m_dialogId;

    QString dialogName;
    const QString DIALOG_URL = "https://securechat-4276e.firebaseio.com/Dialogs/";

    MessageList m_messages;

};


#endif //SECURECHAT_DIALOG_H
