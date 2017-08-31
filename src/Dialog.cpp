//
// Created by ivan on 22.08.17.
//

#include "Dialog.h"

using Json = nlohmann::json;

QString Dialog::DIALOG_URL = "https://securechat-4276e.firebaseio.com/Dialogs/";

Dialog::Dialog(int dialogId, CurrentUser *user) : m_dialogId(dialogId), currentUser(user), QObject(nullptr) {
    m_messages = new MessageList();
    workerThread = new QThread;
}

MessageList *Dialog::dumpMessages() {
    QString response = Request::get(DIALOG_URL + QString::number(2, 10) + QString::fromStdString("/messages.json"));
    Json messages = Json::parse(response.toStdString());
    for (const auto &x : messages) {
        Message msg = Message(QString::fromStdString(x["text"]), QString::fromStdString(x["author"]), x["timestamp"]);
        m_messages->add(msg);
    }

    worker = new MessageWorker(m_messages);
    worker->moveToThread(workerThread);
    workerThread->connect(workerThread, &QThread::started, worker, &MessageWorker::doWork);
    workerThread->start();
    connect(worker, &MessageWorker::updateFinished, this, &Dialog::updateFinished);

    return m_messages;
}

void Dialog::writeMessage(QString text) {
    if (!text.isEmpty()) {
        Message message(text, currentUser->username());
        Request::post(DIALOG_URL + QString::number(2) + "/messages.json", message.toJson());
    }
    return;
}

void Dialog::updateFinished() {
    auto newData = worker->getNewData();
    for (const auto &x : newData) {
        m_messages->add(x);
    }
}
