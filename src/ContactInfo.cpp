//
// Created by ivan on 25.08.17.
//

#include "ContactInfo.h"

ContactInfo::ContactInfo() {

}

ContactInfo::ContactInfo(const ContactInfo &other) {
    this->m_dialogId = other.m_dialogId;
    this->m_username = other.m_username;
}

ContactInfo &ContactInfo::operator=(const ContactInfo &other) {
    this->m_dialogId = other.m_dialogId;
    this->m_username = other.m_username;
    return *this;
}

ContactInfo::~ContactInfo() {

}

int ContactInfo::getDialogId() const {
    return m_dialogId;
}

void ContactInfo::setDialogId(int m_dialogId) {
    ContactInfo::m_dialogId = m_dialogId;
}

