//
// Created by ivan on 22.08.17
//

#include <iostream>
#include <libs/restclient-cpp/restclient.h>
#include "CurrentUser.h"
#include "Dialog.h"
#include "../libs/restclient-cpp/restclient.h"
#include "ContactInfo.h"

using Json = nlohmann::json;

CurrentUser* CurrentUser::m_instance = nullptr;

CurrentUser *CurrentUser::getInstance() {
    if(m_instance == nullptr) {
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
    RestClient::Response response = RestClient::get((USER_URL + m_username + "/contactList.json").toStdString());
    Json json = Json::parse(response.body);
    QList<QObject *> result;
    for(auto &x: json) {
        ContactInfo *contactInfo = new ContactInfo;
        contactInfo->setUsername(QString::fromStdString(x["name"]));
        contactInfo->setDialogId((x["dialogId"]));
        result.append(contactInfo);
    }
    return result;
}

