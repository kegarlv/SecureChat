#include "DialogController.h"

DialogController::DialogController(int dialogId) {
    qDebug() << "new Dialog with " << dialogId;
    m_dialog = new Dialog(dialogId);
}

DialogController::DialogController() {
    qDebug() << "new Dialog with " << 3;
    m_dialog = new Dialog(3);
}

DialogController::~DialogController() {
    delete m_dialog;
    delete m_workerThread;
    delete m_messageWorker;
}

void DialogController::startUpdating() {
    qDebug() << "start updating";
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
    qDebug() << "GetMessageList" << m_dialog->getDialogId();
    startUpdating();
    return m_dialog->getMessageList();
}

void DialogController::sendMessage(const Message &msg) {
    QString requestUrl = DIALOG_URL + QString::number(m_dialog->getDialogId()) + "/messages.json";
    Request::post(requestUrl, msg.toJson());
}

void DialogController::updateFinished() {
    auto newData = m_messageWorker->getNewData();
    for (auto &x : newData) {
        x.setText(CipherHelper::decipher(x.getText()));
        m_dialog->getMessageList()->add(x);
        qDebug() << x.toJson();
    }
}
