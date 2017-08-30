#include "User.h"

User::User(){
}

User::User(const User &other) {
    this->m_username = other.m_username;
}

User &User::operator=(const User &other) {
    this->m_username = other.m_username;
    return *this;
}

QString User::username() const {
    return m_username;
}

void User::setUsername(const QString &username) {
    m_username = username;
}
