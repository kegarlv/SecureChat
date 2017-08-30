#ifndef MESSAGELIST_H
#define MESSAGELIST_H

#include <QtCore/QAbstractListModel>
#include <QList>
#include "Message.h"

class MessageList : public QAbstractListModel {
    Q_OBJECT
public:
    explicit MessageList(QList<Message> messages, QObject *parent = nullptr);
    ~MessageList();

    MessageList(const MessageList &other) {
        this->m_messages = other.m_messages;
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;
    MessageList &operator=(const MessageList &other) {
        this->m_messages = other.m_messages;
        return *this;
    }

    void add(Message msg);

    private:
    QList<Message> m_messages;
};

#endif // MESSAGELIST_H
