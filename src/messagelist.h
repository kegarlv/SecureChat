#ifndef MESSAGELIST_H
#define MESSAGELIST_H

#include <QByteArray>
#include <QHash>
#include <QList>
#include <QtCore/QAbstractListModel>

#include "Message.h"

class MessageList : public QAbstractListModel {
    Q_OBJECT
  public:
    enum MessageListRoles {
        Timestamp = Qt::UserRole + 1,
        Text,
        Author
    };
    explicit MessageList(QList<Message> messages = QList<Message>(), QObject *parent = nullptr);
    MessageList(const MessageList &other);
    MessageList &operator=(const MessageList &other);
    ~MessageList();

    void add(Message msg);
        bool contains(const Message &msg) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

  private:
    QList<Message> m_messages;
};

#endif // MESSAGELIST_H
