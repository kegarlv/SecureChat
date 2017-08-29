//
// Created by ivan on 22.08.17
//

#include "CurrentUser.h"
#include "ContactInfo.h"
#include "Dialog.h"
#include <iostream>

#include "request.h"

using Json = nlohmann::json;

CurrentUser *CurrentUser::m_instance = nullptr;

CurrentUser *CurrentUser::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new CurrentUser();
    }
    return m_instance;
}

CurrentUser::CurrentUser() {
}

CurrentUser::~CurrentUser() {
}

bool CurrentUser::authorize() {
    //find privatekey
    //cipher testmessage
    //decipher testmessage
    //return ...
    return true;
}

Dialog CurrentUser::getDialog(int dialogId) {
    return Dialog(*this, dialogId);
}

QList<QObject *> CurrentUser::getContactList() {
    QString response = Request::get(USER_URL + m_username + "/contactList.json");

    Json json = Json::parse(response.toStdString());
    QList<QObject *> result;
    for (auto &x : json) {
        ContactInfo *contactInfo = new ContactInfo;
        contactInfo->setUsername(QString::fromStdString(x["name"]));
        contactInfo->setDialogId((x["dialogId"]));
        result.append(contactInfo);
    }

    return result;
}
