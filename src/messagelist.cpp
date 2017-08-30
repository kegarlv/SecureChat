#include "messagelist.h"

MessageList::~MessageList() {

}

MessageList::MessageList(QList<Message> messages, QObject *parent) : m_messages(messages), QAbstractListModel(parent) {

}

int MessageList::rowCount(const QModelIndex &parent) const {
    return m_messages.size();
}

QVariant MessageList::data(const QModelIndex &index, int role) const {
    int i = index.row();
    if(i< 0 || i > m_messages.size()) {
        return QVariant(QVariant::Invalid);
    }
    return QVariant::fromValue(m_messages[i].text());
}

void MessageList::add(const Message msg)
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    m_messages << msg;
    endInsertRows();
}
