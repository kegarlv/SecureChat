//
// Created by ivan on 22.08.17.
//

#include <iostream>
#include "Dialog.h"

#include "cipherhelper.h"


using Json = nlohmann::json;

QString Dialog::DIALOG_URL = "https://securechat-4276e.firebaseio.com/Dialogs/";

Dialog::Dialog(int dialogId, CurrentUser *user) : m_dialogId(dialogId), currentUser(user), QObject(nullptr) {
    m_messages = new MessageList();
    workerThread = new QThread;
    QString response = Request::get(DIALOG_URL + QString::number(m_dialogId) + QString::fromStdString("/iv.json"));
    response = response.left(response.size()-1);
    m_iv = response.right(response.size()-1);

    response = Request::get(DIALOG_URL + QString::number(m_dialogId) + QString::fromStdString("/key.json"));
    response = response.left(response.size()-1);
    m_key = response.right(response.size()-1);
}

MessageList *Dialog::dumpMessages() {
    if (worker == nullptr) {
        worker = new MessageWorker(m_messages, m_dialogId);
        worker->moveToThread(workerThread);
        workerThread->connect(workerThread, &QThread::started, worker, &MessageWorker::doWork);
        workerThread->start();
        connect(worker, &MessageWorker::updateFinished, this, &Dialog::updateFinished);
    }
    return m_messages;
}

void Dialog::writeMessage(QString text) {
    if (!text.isEmpty()) {
        Message message(CipherHelper::cipher(text), currentUser->username());
        Request::post(DIALOG_URL + QString::number(m_dialogId) + "/messages.json", message.toJson());
    }
}

void Dialog::updateFinished() {
    auto newData = worker->getNewData();
    for (auto &x : newData) {
        x.setText(CipherHelper::decipher(x.getText()));
        m_messages->add(x);
    }
}
