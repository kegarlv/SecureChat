//
// Created by ivan on 22.08.17.
//

#include <iostream>
#include "Dialog.h"
#include "../libs/restclient-cpp/restclient.h"

using Json = nlohmann::json;

Dialog::Dialog(CurrentUser &currentUser, int dialogId) : currentUser(currentUser), dialogId(dialogId) {

}

std::vector<Message> Dialog::dumpMessages() {
    RestClient::Response response = RestClient::get(DIALOG_URL + std::to_string(dialogId) + "/messages.json");

    Json messages = Json::parse(response.body);
    std::vector<Message> res;
    //std::cout << messages;
    for(const auto &x : messages) {
        res.push_back(Message(x["text"], x["author"], x["timestamp"]));
    }
    return res;
}

void Dialog::writeMessage(std::string text) {
    if(!text.empty()) {
        Message message(text, currentUser.username());
        RestClient::Response response = RestClient::post(DIALOG_URL + std::to_string(dialogId) + "/messages.json",
                                                         "application/json", message.toJson());
    }
}
