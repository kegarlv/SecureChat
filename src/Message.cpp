//
// Created by ivan on 22.08.17.
//

#include "Message.h"
#include <QtCore/QDateTime>

Message::Message(QString text, QString author) : m_text(text), m_author(author), m_timestamp(time(nullptr)) {
}

QString Message::toJson() {
    return "{"
           "\"author\":"
           "\"" +
           m_author + "\"" +
           ",\"text\":" +
           "\"" + m_text + "\"" +
           ",\"timestamp\":" +
           QString::number(m_timestamp) +
           "}";
}

Message::Message(QString text, QString author, time_t timestamp) : m_text(text), m_author(author), m_timestamp(timestamp) {
}

Message::Message(const Message &other) {
    this->m_timestamp = other.m_timestamp;
    this->m_author = other.m_author;
    this->m_text = other.m_text;
}

Message &Message::operator=(const Message &other) {
    this->m_text = other.m_text;
    this->m_author = other.m_author;
    this->m_timestamp = other.m_timestamp;
    return *this;
}

bool Message::operator==(const Message &m2) {
    if(this->timestamp() == m2.timestamp() && this->getAuthor() == m2.getAuthor() && this->text() == m2.text())
        return true;
    return false;
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
