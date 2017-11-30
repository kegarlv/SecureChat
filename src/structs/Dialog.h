//
// Created by ivan on 14.09.17.
//

#ifndef SECURECHAT_DIALOG_H
#define SECURECHAT_DIALOG_H

#include <QObject>
#include <QThread>

#include "src/models/messagelist.h"
#include "src/utils/constants.h"
#include "src/utils/request.h"

class Dialog : public QObject {
    Q_OBJECT
  public:
    explicit Dialog(int dialogId);
    ~Dialog();
    MessageList *getMessageList();

    int getDialogId() const;

    int getMessageCount() const;
    void setMessageCount(int messageCount);

private:
    int m_dialogId;
    int m_messageCount = 0;
    MessageList *m_messageList = nullptr;
    Message m_lastMessage;
};

#endif //SECURECHAT_DIALOG_H
