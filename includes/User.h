#ifndef USER_H
#define USER_H

#include <string>

class User {
  public:
    User(std::string username);
    virtual ~User() = 0;

    std::string username() const;
    void setUsername(const std::string &username);

  private:
    std::string m_username;
};

#endif //USER_H
