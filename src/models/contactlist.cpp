#include "contactlist.h"

int ContactList::rowCount(const QModelIndex &parent) const {
    return m_contactList.size();
}

QVariant ContactList::data(const QModelIndex &index, int role) const {
    int i = index.row();
    if (i < 0 || i > m_contactList.size()) {
        return QVariant(QVariant::Invalid);
    }
    if(role == Username) {
        return m_contactList[i].username();
    } else {
        return m_contactList[i].getDialogId();
    }
}

void ContactList::add(const ContactInfo &contactInfo) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_contactList << contactInfo;
    endInsertRows();
}

QHash<int, QByteArray> ContactList::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[DialogId] = "dialogId";
    roles[Username] = "username";
    return roles;
}

ContactList::ContactList(QList<ContactInfo> contactList) : m_contactList(contactList) {
}

ContactList::ContactList(const ContactList &other) {
    this->m_contactList = other.m_contactList;
}

ContactList &ContactList::operator=(const ContactList &other) {
    this->m_contactList = other.m_contactList;
    return *this;
}
