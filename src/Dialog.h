//
// Created by ivan on 22.08.17.
//

#ifndef SECURECHAT_DIALOG_H
#define SECURECHAT_DIALOG_H

#include "utils/json.h"

#include <QList>
#include <QVariant>
#include <unistd.h>

#include <QDebug>

#include "src/CurrentUser.h"
#include "structs/Message.h"
#include "models/messagelist.h"

#include "utils/request.h"
#include "utils/messageworker.h"
#include "utils/cipherhelper.h"

#include <QThread>

class MessageWorker;
class Dialog : public QObject {
    Q_OBJECT
  public:
    explicit Dialog(int dialogId, CurrentUser *user);
    ~Dialog();
    MessageList *dumpMessages();
    void writeMessage(QString);

    static QString DIALOG_URL;
  public slots:
    void updateFinished();

  private:
    CurrentUser *currentUser;
    int m_dialogId;

    QString m_dialogName;
    QString m_iv;
    QString m_key;

    MessageList *m_messages;
    QThread *workerThread;
    MessageWorker *worker = nullptr;
};

#endif //SECURECHAT_DIALOG_H
