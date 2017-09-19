//
// Created by ivan on 22.08.17.
//

#ifndef SECURECHAT_CURRENTUSER_H
#define SECURECHAT_CURRENTUSER_H

#include "structs/User.h"
#include "utils/json.h"
#include "models/contactlist.h"

#include "utils/request.h"
#include "src/controllers/DialogController.h"

#include <QList>

class CurrentUser : public User {
    CurrentUser();
    static CurrentUser *m_instance;
public:
    static CurrentUser* getInstance();
    ~CurrentUser();

    bool authorize();

    ContactList *getContactList();
    MessageList *getMessageList(int dialogId);

private:
    ContactList *m_contactModel;
    QMap<int, DialogController*> m_dialogControllers;
};


#endif //SECURECHAT_CURRENTUSER_H
