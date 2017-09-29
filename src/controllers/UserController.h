//
// Created by ivan on 20.09.17.
//

#ifndef SECURECHAT_USERCONTROLLER_H
#define SECURECHAT_USERCONTROLLER_H

#include <QObject>
#include <QString>

#include <exception>

class UserController : public QObject {
    Q_OBJECT
public:
    UserController();
    ~UserController() override;

    Q_INVOKABLE void auth(const QString &username);
    void createNewUser(const QString &username);

    QString getUsername();

signals:
    void authorized(bool isAuthorized);

private:
    QString m_username = "";
    bool m_isAuthorized = false;
};


#endif //SECURECHAT_USERCONTROLLER_H
