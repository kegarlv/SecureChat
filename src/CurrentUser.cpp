//
// Created by ivan on 22.08.17
//

#include "CurrentUser.h"

using Json = nlohmann::json;

CurrentUser *CurrentUser::m_instance = nullptr;

CurrentUser *CurrentUser::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new CurrentUser();
    }
    return m_instance;
}

CurrentUser::CurrentUser() {
    m_contactModel = new ContactList;
}

CurrentUser::~CurrentUser() {
}

bool CurrentUser::authorize() {

    //find privatekey
    //cipher testmessage
    //decipher testmessage
    //or
    //return ...
    return true;
}

ContactList *CurrentUser::getContactList() {
    QString response = Request::get(USER_URL + m_username + "/contactList.json");

    Json json = Json::parse(response.toStdString());
    for (auto &x : json) {
        ContactInfo contactInfo;
        contactInfo.setUsername(QString::fromStdString(x["name"]));
        contactInfo.setDialogId((x["dialogId"]));
        m_contactModel->add(contactInfo);
        m_dialogControllers.insert(contactInfo.getDialogId(), new DialogController(contactInfo.getDialogId()));
    }

    return m_contactModel;
}

MessageList *CurrentUser::getMessageList(int dialogId) {
    m_dialogControllers[dialogId]->startUpdating();
    return m_dialogControllers[dialogId]->getMessageList();
}
