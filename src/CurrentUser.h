//
// Created by ivan on 22.08.17.
//

#ifndef SECURECHAT_CURRENTUSER_H
#define SECURECHAT_CURRENTUSER_H

#include "User.h"
class Dialog;

class CurrentUser : public User {
    CurrentUser();
    static CurrentUser *m_instance;
public:
    static CurrentUser* getInstance();
    ~CurrentUser();

    /**
     * Authorizes user in system
     * @return user authorized
     */
    bool authorize();

    Dialog* createDialog(int num);

private:
    Dialog *dialog;


};


#endif //SECURECHAT_CURRENTUSER_H
