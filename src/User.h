#ifndef USER_H
#define USER_H

#include <string>
#include <ostream>

class User {
  public:
    User();

    std::string username() const;
    void setUsername(const std::string &username);


private:
    std::string m_username;
};

#endif //USER_H
