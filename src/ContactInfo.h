//
// Created by ivan on 25.08.17.
//

#ifndef SECURECHAT_CONTACTINFO_H
#define SECURECHAT_CONTACTINFO_H

#include <QtCore/QAbstractListModel>
#include "User.h"

class ContactInfo : public User {
    Q_OBJECT
    Q_PROPERTY(int dialogId READ getDialogId WRITE setDialogId NOTIFY dialogIdChanged)
public:
    ContactInfo();
    ~ContactInfo();

    int getDialogId() const;
    void setDialogId(int m_dialogId);

    signals:
    void dialogIdChanged();

private:
    int m_dialogId;

};

class ContactModel : public QAbstractListModel {
public:
    ContactModel(QList<QObject*> contactList);
    int rowCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;

private:
    QList<QObject *> m_contactList;
};



#endif //SECURECHAT_CONTACTINFO_H
