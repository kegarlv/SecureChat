#include "cipherhelper.h"

QString CipherHelper::key = "7D9BB722DA2DC8674E08C3D44AAE976F";
QString CipherHelper::iv = "37C6D22FADE22B2D924598BEE2455EFC";

CipherHelper::CipherHelper() {
}

string CipherHelper::cipher(string instring) {
    CFB_Mode<AES>::Encryption cfbEncryption((byte *)key.toStdString().c_str(), key.size(), (byte *)iv.toStdString().c_str());
    char plainText[instring.size() + 1];
//    bzero(plainText,instring.size() + 1);
    cfbEncryption.ProcessData((byte *)plainText, (byte *)instring.c_str(), instring.size() + 1);
    return plainText;
}

string CipherHelper::decipher(string instring) {
    CFB_Mode<AES>::Decryption cfbDecryption((byte *)key.toStdString().c_str(), key.size(), (byte *)iv.toStdString().c_str());
    char plainText[instring.size() + 1];
    bzero(plainText,instring.size() + 1);
    cfbDecryption.ProcessData((byte *)plainText, (byte *)instring.c_str(), instring.length() + 1);
    return plainText;
}
