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

private:
    int m_dialogId;
    MessageList *m_messageList = nullptr;
};

#endif //SECURECHAT_DIALOG_H
