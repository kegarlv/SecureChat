//
// Created by ivan on 20.09.17.
//

#include "UserController.h"

QString UserController::m_username = "";
bool UserController::m_isAuthorized = false;

UserController::UserController() = default;

UserController::~UserController() = default;

void UserController::auth(const QString &username) {
    //TODO implement auth
    //Possible in another thread
    UserController::m_username = username;
    m_isAuthorized = true;

    //workaround
    emit authorized(true);
    return;
}

void UserController::createNewUser(const QString &username) {
    //TODO implement me
}

QString UserController::getUsername() {
    if(m_isAuthorized)
        return UserController::m_username;
    throw std::invalid_argument("User must be authorized");
}
