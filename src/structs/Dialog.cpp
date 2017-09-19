#include "Dialog.h"

Dialog::Dialog(int dialogId) : m_dialogId(dialogId) {
    m_messageList = new MessageList();
}

Dialog::~Dialog() {
    delete m_messageList;
}

MessageList *Dialog::getMessageList() {
    return m_messageList;
}

int Dialog::getDialogId() const
{
    return m_dialogId;
}
