#ifndef CIPHERHELPER_H
#define CIPHERHELPER_H

#include <QDebug>
#include <QString>

#include <string>

#include <cryptopp/default.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>
#include <cryptopp/files.h>
#include <cryptopp/hex.h>

using CryptoPP::HexEncoder;
using CryptoPP::FileSource;
using CryptoPP::HexDecoder;
using CryptoPP::StringSource;
using CryptoPP::StringSink;
using CryptoPP::DefaultEncryptorWithMAC;
using CryptoPP::DefaultDecryptorWithMAC;

using namespace CryptoPP;
using namespace std;

class CipherHelper {
  public:
    CipherHelper();

    static QString cipher(QString instring);
    static QString decipher(QString instring);

    static QString key;
    static QString iv;
};

#endif // CIPHERHELPER_H
