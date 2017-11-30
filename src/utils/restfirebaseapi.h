#ifndef RESTFIREBASEAPI_H
#define RESTFIREBASEAPI_H

#include "firebaseapi.h"
#include "request.h"
#include "constants.h"

#include <QImage>

class RestFirebaseAPI : public FirebaseAPI {
  public:
    ~RestFirebaseAPI() override;
    virtual QJsonArray getContactList(const QString &username) override;
    virtual void sendMessage(const int dialogId, const Message &message) override;
    virtual QJsonObject getMessages(const int dialogId) override;

    /**
     * @brief getAvatar Smart getter with cache
     * @param username
     * @return
     */
    virtual QImage getAvatar(const QString &username) override;
    //TODO add setAvatar
};

#endif // RESTFIREBASEAPI_H
