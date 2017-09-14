//
// Created by ivan on 22.08.17.
//

#ifndef SECURECHAT_MESSAGE_H
#define SECURECHAT_MESSAGE_H

#include <ctime>
#include <QtCore/QObject>
#include <QtCore/QDateTime>
#include <QString>

class Message : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString timestamp READ timestamp WRITE setTimestamp NOTIFY textChanged)
    Q_PROPERTY(QString author READ getAuthor WRITE setAuthor NOTIFY authorChanged)

public:
    Message();
    Message(QString text, QString author);
    Message(QString text, QString author, time_t timestamp);
    Message(const Message &other);
    Message &operator=(const Message &other);
    bool operator==(const Message &m2);
    friend bool operator==(const Message &m1, const Message &m2);

    QString toJson();

    Q_INVOKABLE QString getText() {return m_text;}
    QString text() const;
    void setText(const QString &text);

    QString getAuthor() const;
    void setAuthor(const QString &author);

    QString timestamp() const;
    void setTimestamp(QString timestamp);
signals:
    void textChanged();
    void authorChanged();

public:
    QString m_text;
    QString m_author;
    time_t m_timestamp;
};

#endif //SECURECHAT_MESSAGE_H
