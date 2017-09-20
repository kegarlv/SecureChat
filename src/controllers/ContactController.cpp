#include "ContactController.h"

ContactController::ContactController() {
    m_contactList = new ContactList;
}

ContactController::~ContactController() {
    delete m_contactList;
}

ContactList *ContactController::getContactList() {
    //TODO fix username
    QString response = Request::get(USER_URL + "Ivan Voloshyn" + "/contactList.json");

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(response.toUtf8(), &err);
    QJsonArray obj = doc.array();

    qDebug() << response;
    for(auto x:obj) {
        ContactInfo contactInfo;
        contactInfo.setUsername((x.toObject())["name"].toString(""));
        contactInfo.setDialogId((x.toObject())["dialogId"].toInt(-1));
        m_contactList->add(contactInfo);
    }

    return m_contactList;
}