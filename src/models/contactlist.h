#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "src/structs/ContactInfo.h"
#include <QAbstractListModel>
#include <QDebug>
#include <QList>
#include <QModelIndex>

class ContactList : public QAbstractListModel {
  public:
    enum MyRoles {
        DialogId = Qt::UserRole + 1,
        Username
    };

    ContactList(QList<ContactInfo> contactList = QList<ContactInfo>());
    ContactList(const ContactList &other);
    ContactList &operator=(const ContactList &other);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    void add(const ContactInfo &contactInfo);

    virtual QHash<int, QByteArray> roleNames() const override;

  private:
    QList<ContactInfo> m_contactList;
};

#endif // CONTACTLIST_H
