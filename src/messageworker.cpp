#include "messageworker.h"

using Json = nlohmann::json;

MessageWorker::MessageWorker(MessageList *messageList) : m_messageList(messageList) {
}

void MessageWorker::doWork() {
    while (1) {
        QString response = Request::get(Dialog::DIALOG_URL + QString::number(2, 10) + QString::fromStdString("/messages.json"));
        Json messages = Json::parse(response.toStdString());
        for (const auto &x : messages) {
            Message msg = Message(QString::fromStdString(x["text"]), QString::fromStdString(x["author"]), x["timestamp"]);
            if (!(newData.contains(msg) || m_messageList->contains(msg))) {
                newData.push_back(msg);
            }
        }
        emit updateFinished();
    }
}

QVector<Message> MessageWorker::getNewData() {
    auto tmp = newData;
    newData.clear();
    return tmp;
}
