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
