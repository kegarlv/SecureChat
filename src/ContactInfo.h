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
    ContactInfo(const ContactInfo &other);
    ContactInfo &operator=(const ContactInfo &other);

    ~ContactInfo();

    int getDialogId() const;
    void setDialogId(int m_dialogId);

    signals:
    void dialogIdChanged();

private:
    int m_dialogId;

};



#endif //SECURECHAT_CONTACTINFO_H
