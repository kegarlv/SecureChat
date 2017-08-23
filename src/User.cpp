#include "User.h"

User::User(){
}

std::string User::username() const {
    return m_username;
}

void User::setUsername(const std::string &username) {
    m_username = username;
}