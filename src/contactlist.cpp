#include "contactlist.h"

int ContactModel::rowCount(const QModelIndex &parent) const {
    return m_contactList.size();
}

QVariant ContactModel::data(const QModelIndex &index, int role) const {
    int i = index.row();
    if (i < 0 || i > m_contactList.size()) {
        return QVariant(QVariant::Invalid);
    }
    if(role == Username) {
        qDebug() << m_contactList[i].username();
        return m_contactList[i].username();
    } else {
        return m_contactList[i].getDialogId();
    }
}

void ContactModel::add(const ContactInfo &contactInfo) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_contactList << contactInfo;
    endInsertRows();
}

QHash<int, QByteArray> ContactModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[DialogId] = "dialogId";
    roles[Username] = "username";
    return roles;
}

ContactModel::ContactModel(QList<ContactInfo> contactList) : m_contactList(contactList) {
}

ContactModel::ContactModel(const ContactModel &other) {
    this->m_contactList = other.m_contactList;
}

ContactModel &ContactModel::operator=(const ContactModel &other) {
    this->m_contactList = other.m_contactList;
    return *this;
}
