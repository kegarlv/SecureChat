//
// Created by ivan on 22.08.17.
//

#include <iostream>
#include <libs/restclient-cpp/restclient.h>
#include "Dialog.h"
#include "../libs/restclient-cpp/restclient.h"

using Json = nlohmann::json;

Dialog::Dialog(CurrentUser &currentUser, int dialogId) : currentUser(currentUser), dialogId(dialogId) {

}

QList<QObject*> Dialog::dumpMessages() {
    RestClient::Response response = RestClient::get((DIALOG_URL + QString::number(2, 10) + QString::fromStdString("/messages.json")).toStdString());

    Json messages = Json::parse(response.body);
    for(const auto &x : messages) {
        Message *msg =  new Message(QString::fromStdString(x["text"]), QString::fromStdString(x["author"]), x["timestamp"]);
        m_messages.append(msg);
    }

    void* pointerToMsg = &m_messages;
    std::thread requestMessages([pointerToMsg, *this] {
        try {
//            while(1) {

                    RestClient::Response response = RestClient::get(
                            (DIALOG_URL + QString::number(2, 10) +
                             QString::fromStdString("/messages.json")).toStdString());

                std::cout << response.body;
                    Json messages = Json::parse(response.body);
                    (reinterpret_cast<QList<QObject *> * >(pointerToMsg))->clear();
                    for (const auto &x : messages) {
                        Message *msg = new Message(QString::fromStdString(x["text"]), QString::fromStdString(x["author"]),
                                                   x["timestamp"]);
                        (reinterpret_cast<QList<QObject *> * >(pointerToMsg))->append(msg);

                    }
                    sleep(1000);
//                }
            }
        catch (...) {
            std::cout << "Error occured";
        }
    });
    requestMessages.detach();
    return m_messages;
}

void Dialog::writeMessage(QString text) {
    if(!text.isEmpty()) {
        Message message(text, currentUser.username());
        RestClient::Response response = RestClient::post((DIALOG_URL + QString::number(dialogId) + QString::fromStdString("/messages.json")).toStdString(),"application/json", message.toJson().toStdString());
    }
}
