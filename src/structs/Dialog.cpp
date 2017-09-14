#include "Dialog.h"

Dialog::Dialog(int dialogId) : m_dialogId(dialogId) {
    m_messageList = new MessageList();
}

Dialog::~Dialog() {
    delete m_messageList;
}
