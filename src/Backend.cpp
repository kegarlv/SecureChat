//
// Created by ivan on 23.08.17.
//

#include <iostream>
#include "Backend.h"

Backend::Backend() {
    currentUser = CurrentUser::getInstance();

}

void Backend::setUsername(const QString &username) {
    currentUser->setUsername(username);

}

QString Backend::username() {
    return currentUser->username();
}

bool Backend::authorize() {
    return currentUser->authorize();
}

void Backend::sendMessage(int dialogId, const QString &text) {
    currentUser->getDialog(dialogId).writeMessage(text);
}

Backend::~Backend() {

}

QList<QObject *> Backend::getContactList() {
    return currentUser->getContactList();
}

QList<QObject *> Backend::getMessages() {
    qDebug() << "Get Messages";
    return currentUser->getDialog(1).dumpMessages();
}

QList<QObject *> Backend::getMsg() {
    qDebug() << "Get msg";
    return currentUser->getDialog(1).dumpMessages();
}
