//
// Created by ivan on 22.08.17.
//

#include "Message.h"

Message::Message(std::string text, std::string author) :text(text),author(author),timestamp(time(nullptr)) {

}

std::string Message::toJson() {
    return "{"
        "\"author\":"
           "\"" + author + "\"" +
           ",\"text\":" +
           "\"" + text + "\"" +
           ",\"timestamp\":" +
           std::to_string(timestamp) +
           "}";
}

Message::Message(std::string text, std::string author, time_t timestamp):text(text),author(author),timestamp(timestamp) {

}

std::string Message::toHuman() {

    tm *ltm = localtime(&timestamp);

    char buffer[80] = {0};
    strftime(buffer,80, "%I:%m", ltm);
    return author + " @ " +  buffer + " : " + text;
}
