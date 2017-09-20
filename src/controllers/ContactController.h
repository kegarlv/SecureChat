#ifndef CONTACT_CONTROLLER
#define CONTACT_CONTROLLER

#include <QObject>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonParseError>

#include <QDebug>

#include "src/models/contactlist.h"

#include "src/utils/request.h"
#include "src/utils/constants.h"

class ContactController : public QObject {
    Q_OBJECT
  public:
    ContactController();
    ~ContactController();

    Q_INVOKABLE ContactList *getContactList();

  private:
    ContactList *m_contactList = nullptr;
};

#endif //CONTACT_CONTROLLER
