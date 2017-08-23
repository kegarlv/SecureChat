//
// Created by ivan on 22.08.17.
//

#ifndef SECURECHAT_DIALOG_H
#define SECURECHAT_DIALOG_H


#include <vector>
#include "CurrentUser.h"
#include "Message.h"

#include "../libs/restclient-cpp/restclient.h"
#include "../libs/restclient-cpp/helpers.h"

#include "../libs/json.h"

class Dialog {

public:
    explicit Dialog(CurrentUser &currentUser, int dialogId);

    std::vector<Message> dumpMessages();
    void writeMessage(std::string);

private:
    CurrentUser &currentUser;
    int dialogId;

    std::string dialogName;
    const std::string DIALOG_URL = "https://securechat-4276e.firebaseio.com/Dialogs/";


};


#endif //SECURECHAT_DIALOG_H
