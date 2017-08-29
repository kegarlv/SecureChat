//
// Created by ivan on 22.08.17.
//

#include <iostream>
#include <QtCore/QDateTime>
#include "Message.h"

Message::Message(QString text, QString author): m_text(text),m_author(author),m_timestamp(time(nullptr)) {
    std::cout << text.toStdString();
}

QString Message::toJson() {
    return "{"
        "\"author\":"
           "\"" + m_author + "\"" +
           ",\"text\":" +
           "\"" + m_text + "\"" +
           ",\"timestamp\":" +
           QString::number(m_timestamp,10) +
           "}";
}


Message::Message(QString text, QString author, time_t timestamp) : m_text(text),m_author(author),m_timestamp(timestamp) {
  std::cout << text.toStdString();
}
 QString Message::text() const {
    return m_text;
}

void Message::setText(const QString &text) {
    Message::m_text = text;
}

const QString &Message::getAuthor() const {
    return m_author;
}

void Message::setAuthor(const QString &author) {
    m_author = author;
}

QString Message::timestamp() const {
    return QDateTime::fromSecsSinceEpoch(m_timestamp).toString("d MMM hh:mm");
}

void Message::setTimestamp(QString timestamp) {
    m_timestamp = timestamp.toInt();
}

MessageList::~MessageList() {

}

MessageList::MessageList(QList<QObject*> messages, QObject *parent) : m_messages(messages), QAbstractListModel(parent) {

}

int MessageList::rowCount(const QModelIndex &parent) const {
    return m_messages.size();
}

QVariant MessageList::data(const QModelIndex &index, int role) const {
    int i = index.row();
    if(i< 0 || i > m_messages.size()) {
        return QVariant(QVariant::Invalid);
    }
    return QVariant::fromValue(m_messages[i]);
}
