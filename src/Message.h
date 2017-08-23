//
// Created by ivan on 22.08.17.
//

#ifndef SECURECHAT_MESSAGE_H
#define SECURECHAT_MESSAGE_H

#include <string>
#include <ctime>

class Message {
public:
    Message(std::string text, std::string author);
    Message(std::string text, std::string author, time_t timestamp);

    std::string toJson();
    std::string toHuman();

private:
    std::string text;
    std::string author;
    time_t timestamp;

};


#endif //SECURECHAT_MESSAGE_H
