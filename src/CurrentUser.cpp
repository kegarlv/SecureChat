//
// Created by ivan on 22.08.17
//

#include "CurrentUser.h"

CurrentUser *CurrentUser::m_instance = nullptr;

CurrentUser::CurrentUser()
{

}

CurrentUser *CurrentUser::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new CurrentUser();
    }
    return m_instance;
}

CurrentUser::~CurrentUser() {
}

bool CurrentUser::authorize() {

    //find privatekey
    //cipher testmessage
    //decipher testmessage
    //or
    //return ...
    return true;
}
