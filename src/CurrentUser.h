//
// Created by ivan on 22.08.17.
//

#ifndef SECURECHAT_CURRENTUSER_H
#define SECURECHAT_CURRENTUSER_H

#include <QList>
#include "src/structs/User.h"

class CurrentUser : public User {
    CurrentUser();
    static CurrentUser *m_instance;
public:

    static CurrentUser* getInstance();
    ~CurrentUser();

    bool authorize();
private:

};


#endif //SECURECHAT_CURRENTUSER_H
