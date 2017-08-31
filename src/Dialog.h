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

#include "messageworker.h"
#include <QThread>

class MessageWorker;
class Dialog : public QObject {
    Q_OBJECT
public:
    explicit Dialog(int dialogId, CurrentUser *user);

    MessageList *dumpMessages();
    void writeMessage(QString);

    static QString DIALOG_URL;
public slots:
    void updateFinished();

private:
    CurrentUser *currentUser;
    int m_dialogId;

    QString dialogName;

    MessageList* m_messages;
    QThread *workerThread;
    MessageWorker *worker;

};

#endif //SECURECHAT_DIALOG_H
