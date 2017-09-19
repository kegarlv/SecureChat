//
// Created by ivan on 23.08.17.
//

#include "Backend.h"

QString Backend::getUsername() {
//    return currentUser->username();
}

void Backend::sendMessage(int dialogId, const QString &text) {
    //    currentUser->getDialog(dialogId)->writeMessage(text);
}


ContactList *Backend::getContactList() {
    return m_currentUser->getContactList();
}

Backend::Backend(const QString &username) {
    m_currentUser = CurrentUser::getInstance();
    m_currentUser = CurrentUser::getInstance();
    m_currentUser->setUsername(username);
    m_currentUser->authorize();
}

Backend::~Backend() {
}

MessageList *Backend::getMessages(int dialogId) {
    return m_currentUser->getMessageList(dialogId);
}
