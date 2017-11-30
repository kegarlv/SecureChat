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

    static QString getUsername();

signals:
    void authorized(bool isAuthorized);

private:
    static QString m_username;
    static bool m_isAuthorized;
};


#endif //SECURECHAT_USERCONTROLLER_H
