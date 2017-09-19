#include "messageworker.h"

using Json = nlohmann::json;

MessageWorker::MessageWorker(Dialog *dialog) : m_dialog(dialog){
}

void MessageWorker::doWork() {
    while (1) {
        QString response = Request::get(DIALOG_URL + QString::number(m_dialog->getDialogId()) + QString::fromStdString("/messages.json"));
        Json messages = Json::parse(response.toStdString());
        for (const auto &x : messages) {
            Message msg = Message(QString::fromStdString(x["text"]), QString::fromStdString(x["author"]), x["timestamp"]);
            if (!(newData.contains(msg) || m_dialog->getMessageList()->contains(msg))) {
                newData.push_back(msg);
            }
        }
        emit updateFinished();
    }
}

QVector<Message> MessageWorker::getNewData() {
    QVector<Message> tmp = newData;
    newData.clear();
    return tmp;
}
