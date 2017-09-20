#ifndef USER_H
#define USER_H

#include <QtCore/QString>
#include <QtCore/QObject>

class User : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
  public:
    User();
    User(const User &other);
    User &operator=(const User &other);

    QString username() const;
    void setUsername(const QString &username);

  signals:
    void usernameChanged();

protected:
    QString m_username;
};

#endif //USER_H
