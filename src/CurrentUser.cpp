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
    m_contactModel = new ContactModel;
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
    return Dialog(dialogId);
}

ContactModel* CurrentUser::getContactList() {
    QString response = Request::get(USER_URL + m_username + "/contactList.json");

    Json json = Json::parse(response.toStdString());
    for (auto &x : json) {
        ContactInfo contactInfo;
        contactInfo.setUsername(QString::fromStdString(x["name"]));
        contactInfo.setDialogId((x["dialogId"]));
        m_contactModel->add(contactInfo);
    }

    return m_contactModel;
}
