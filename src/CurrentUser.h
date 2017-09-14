//
// Created by ivan on 22.08.17.
//

#ifndef SECURECHAT_CURRENTUSER_H
#define SECURECHAT_CURRENTUSER_H

#include "structs/User.h"
#include "utils/json.h"
#include "models/contactlist.h"
#include "Dialog.h"

#include "utils/request.h"

#include <QList>

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
