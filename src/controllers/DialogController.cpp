#include "DialogController.h"

DialogController::DialogController(int dialogId) {
    m_dialog = new Dialog(dialogId);
}

DialogController::DialogController() = default;

DialogController::~DialogController() {
    delete m_dialog;
    //TODO
    //Find correct way to stop updating...
    delete m_workerThread;
    delete m_messageWorker;
}

int DialogController::getDialogID() {
    return m_dialog != nullptr ? m_dialog->getDialogId() : -1;
}

void DialogController::setDialogID(int dialogID) {
    delete m_dialog;
    m_dialog = new Dialog(dialogID);
}

void DialogController::startUpdating() {
    m_workerThread = new QThread;
    m_messageWorker = new MessageWorker(m_dialog);
    m_messageWorker->moveToThread(m_workerThread);
    m_workerThread->connect(m_workerThread, &QThread::started, m_messageWorker, &MessageWorker::doWork);
    connect(m_messageWorker, &MessageWorker::updateFinished, this, &DialogController::updateFinished);
    m_workerThread->start();
}

void DialogController::stopUpdating() {
    m_workerThread->exit(0);
    delete m_workerThread;
    delete m_messageWorker;
}

MessageList *DialogController::getMessageList() {
    if (m_dialog != nullptr) {
        startUpdating();
    }
    return m_dialog->getMessageList();
}

void DialogController::sendMessage(const QString &messageText) {
    Message msg(messageText, "Ivan Voloshyn");
    QString requestUrl = DIALOG_URL + QString::number(m_dialog->getDialogId()) + "/messages.json";
    Request::post(requestUrl, msg.toJson());
}

void DialogController::updateFinished() {
    auto newData = m_messageWorker->getNewData();
    for (auto &x : newData) {
        x.setText(CipherHelper::decipher(x.getText()));
        m_dialog->getMessageList()->add(x);
    }
}
