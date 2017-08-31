//
// Created by ivan on 23.08.17.
//

#include "Backend.h"
#include <iostream>

Backend::Backend() {
    currentUser = CurrentUser::getInstance();
}

void Backend::setUsername(const QString &username) {
    currentUser->setUsername(username);
}

QString Backend::getUsername() {
    return currentUser->username();
}

bool Backend::authorize() {
    return currentUser->authorize();
}

void Backend::sendMessage(int dialogId, const QString &text) {
    currentUser->getDialog(dialogId)->writeMessage(text);
}

ContactModel *Backend::getContactList() {
    return currentUser->getContactList();
}

Backend::~Backend() {
}

MessageList *Backend::getMessages(int dialogId) {
    return currentUser->getDialog(dialogId)->dumpMessages();
}
