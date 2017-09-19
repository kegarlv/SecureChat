#include "cipherhelper.h"

QString CipherHelper::key = "7D9BB722DA2DC8674E08C3D44AAE976F";

CipherHelper::CipherHelper() {
}

QString CipherHelper::cipher(QString instring) {
//    std::string encrypted;
//    auto *stringSink = new StringSink(encrypted);
//    HexEncoder *hexEncoder = new HexEncoder(stringSink);
//    DefaultEncryptorWithMAC *defaultEncryptorWithMAC = new DefaultEncryptorWithMAC((byte*)key.toStdString().data(), key.size(),hexEncoder);
//    StringSource ss1(instring.toStdString(), true,defaultEncryptorWithMAC);
//    return QString::fromStdString(encrypted);
    return instring;
}

QString CipherHelper::decipher(QString instring) {
//    std::string decrypted;
//    auto *stringSink = new StringSink(decrypted);
//    DefaultDecryptorWithMAC *decryptorWithMAC = new DefaultDecryptorWithMAC((byte*)key.toStdString().data(), key.size(),stringSink);
//    HexDecoder *hexDecoder = new HexDecoder(decryptorWithMAC);

//    StringSource ss1(instring.toStdString(),true,hexDecoder);
//    return QString::fromStdString(decrypted);
    return instring;
}
