#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <QAbstractListModel>
#include <QList>
#include <QModelIndex>
#include <QDebug>
#include "ContactInfo.h"

class ContactModel : public QAbstractListModel {
public:

    enum MyRoles {
        DialogId = Qt::UserRole + 1,
        Username
    };

    ContactModel(QList<ContactInfo> contactList = QList<ContactInfo>());
    ContactModel(const ContactModel &other);
    ContactModel &operator=(const ContactModel &other);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    void add(const ContactInfo &contactInfo);

    virtual QHash<int, QByteArray> roleNames() const override;

private:
    QList<ContactInfo> m_contactList;
};



#endif // CONTACTLIST_H
