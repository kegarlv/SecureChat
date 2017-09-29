#ifndef CRYPTAPI_H
#define CRYPTAPI_H

#include <QString>

class CryptAPI {
  public:
    CryptAPI() = default;
    virtual ~CryptAPI() = 0;

    virtual QString encrypt(const QString &openText) = 0;
    virtual QString decrypt(const QString &encryptedText) = 0;
};

#endif // CRYPTAPI_H
