#ifndef USER_H
#define USER_H

#include <string>
#include <ostream>
#include <QtCore/QString>
#include <QtCore/QObject>

class User : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
  public:
    User();

    QString username() const;
    void setUsername(const QString &username);

  signals:
    void usernameChanged();


protected:
    QString m_username;
    const QString USER_URL = "https://securechat-4276e.firebaseio.com/Users/";
};

#endif //USER_H
