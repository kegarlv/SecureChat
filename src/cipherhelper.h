#ifndef CIPHERHELPER_H
#define CIPHERHELPER_H

#include <QDebug>
#include <QString>

#include "libs/cryptopp/aes.h"     // For AES
#include "libs/cryptopp/filters.h" //For StringSource
#include "libs/cryptopp/hex.h"     // For HexDecoder
#include "libs/cryptopp/modes.h"   // For CTR_Mode

#include "libs/cryptopp/aes.h"
#include "libs/cryptopp/cryptlib.h"
#include "libs/cryptopp/filters.h"
#include "libs/cryptopp/hex.h"
#include "libs/cryptopp/modes.h"
#include "libs/cryptopp/osrng.h"

#include <string>

using CryptoPP::AutoSeededRandomPool;
using CryptoPP::Exception;
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;
using CryptoPP::AES;

using namespace CryptoPP;
using CryptoPP::CFB_Mode;
using namespace std;

class CipherHelper {
  public:
    CipherHelper();

    static string cipher(string instring);
    static string decipher(string instring);

    static QString key;
    static QString iv;
};

#endif // CIPHERHELPER_H
