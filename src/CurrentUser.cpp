//
// Created by ivan on 22.08.17
//

#include "CurrentUser.h"
#include "Dialog.h"

CurrentUser* CurrentUser::m_instance = nullptr;

CurrentUser *CurrentUser::getInstance() {
    if(m_instance == nullptr) {
        m_instance = new CurrentUser();
    }
    return m_instance;
}

CurrentUser::CurrentUser() {

}

CurrentUser::~CurrentUser() {

}

bool CurrentUser::authorize() {
    //find privatekey
    //cipher testmessage
    //decipher testmessage
    //return ...
    return true;
}

Dialog *CurrentUser::createDialog(int num) {
    dialog = new Dialog(*this, num);
    return dialog;
}
