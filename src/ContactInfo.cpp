//
// Created by ivan on 25.08.17.
//

#include "ContactInfo.h"

ContactInfo::ContactInfo() {

}

ContactInfo::~ContactInfo() {

}

int ContactInfo::getDialogId() const {
    return m_dialogId;
}

void ContactInfo::setDialogId(int m_dialogId) {
    ContactInfo::m_dialogId = m_dialogId;
}

int ContactModel::rowCount(const QModelIndex &parent) const {
    return m_contactList.size();
}

QVariant ContactModel::data(const QModelIndex &index, int role) const {
    int i = index.row();
    if(i < 0 || i > m_contactList.size()) {
        return QVariant(QVariant::Invalid);
    }
    return m_contactList[i]->property("username");

}

ContactModel::ContactModel(QList<QObject *> contactList) : m_contactList(contactList) {

}
