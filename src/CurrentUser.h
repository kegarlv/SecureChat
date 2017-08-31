//
// Created by ivan on 22.08.17.
//

#ifndef SECURECHAT_CURRENTUSER_H
#define SECURECHAT_CURRENTUSER_H

#include <vector>
#include "User.h"
#include "../libs/json.h"

#include "contactlist.h"

#include <QList>

class Dialog;

class CurrentUser : public User {
    CurrentUser();
    static CurrentUser *m_instance;
public:
    static CurrentUser* getInstance();
    ~CurrentUser();

    bool authorize();
    Dialog* getDialog(int dialogId);

    ContactModel *getContactList();

private:
    QMap<int, Dialog*> m_dialogs;
    ContactModel *m_contactModel;
};


#endif //SECURECHAT_CURRENTUSER_H
