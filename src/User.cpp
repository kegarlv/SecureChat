#include "User.h"

User::User(){
}

User::User(const User &other) {
    this->m_username = other.m_username;
}

QString User::username() const {
    return m_username;
}

void User::setUsername(const QString &username) {
    m_username = username;
}
