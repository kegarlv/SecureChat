#include "messagelist.h"

#include <QDebug>
MessageList::~MessageList() {
}

bool MessageList::contains(const Message &msg) const {
    return m_messages.contains(msg);
}

MessageList::MessageList(const MessageList &other) {
    this->m_messages = other.m_messages;
}

MessageList::MessageList(QList<Message> messages, QObject *parent) : m_messages(messages), QAbstractListModel(parent) {
}

int MessageList::rowCount(const QModelIndex &parent) const {
    return m_messages.size();
}

QVariant MessageList::data(const QModelIndex &index, int role) const {
    int i = index.row();
    if (i < 0 || i > m_messages.size()) {
        return QVariant(QVariant::Invalid);
    }
    MessageListRoles roles = MessageListRoles(role);
    switch (roles) {
    case MessageList::Text:
        return m_messages[i].text();
    case MessageList::Author:
        return m_messages[i].getAuthor();
    case Timestamp:
        return m_messages[i].timestamp();
    }
}

QHash<int, QByteArray> MessageList::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[Timestamp] = "timestamp";
    roles[Text] = "message";
    roles[Author] = "author";
    return roles;
}

MessageList &MessageList::operator=(const MessageList &other) {
    this->m_messages = other.m_messages;
    return *this;
}

void MessageList::add(const Message msg) {
    if (!m_messages.contains(msg)) {
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        m_messages << msg;
        endInsertRows();
    }
}
