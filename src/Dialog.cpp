//
// Created by ivan on 22.08.17.
//

#include "Dialog.h"

using Json = nlohmann::json;

Dialog::Dialog(int dialogId) : m_dialogId(dialogId), m_messages(QList<Message>()) {
}

MessageList Dialog::dumpMessages() {

    QString response = Request::get(DIALOG_URL + QString::number(2, 10) + QString::fromStdString("/messages.json"));
    Json messages = Json::parse(response.toStdString());
    for (const auto &x : messages) {
        Message msg = Message(QString::fromStdString(x["text"]), QString::fromStdString(x["author"]), x["timestamp"]);
        m_messages.add(msg);
    }
    return m_messages;
}

void Dialog::writeMessage(QString text) {
    if (!text.isEmpty()) {
        Message message(text, currentUser->username());
        qDebug() << "Message written";
    }
}
