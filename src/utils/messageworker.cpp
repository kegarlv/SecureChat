#include "messageworker.h"

using Json = nlohmann::json;

MessageWorker::MessageWorker(Dialog *dialog) : m_dialog(dialog) {
    m_firebaseApi = new RestFirebaseAPI();
    qDebug() << "MessageWorker created w/" << dialog->getDialogId();
}

MessageWorker::~MessageWorker() {
    delete m_firebaseApi;
}

void MessageWorker::doWork() {
    while (m_isWorking) {
        //TODO improve network performance by using startAt
        QJsonObject messages = m_firebaseApi->getMessages(m_dialog->getDialogId(), m_dialog->getMessageCount());
        for (auto e : messages) {
            Message msg;
            msg.setAuthor((e.toObject())["author"].toString(""));
            msg.setText((e.toObject())["text"].toString(""));
            msg.setTimestamp((e.toObject())["timestamp"].toString(""));

            if(!newData.contains(msg)) {
                newData.push_back(msg);
            }
        }
        emit updateFinished();
    }
}

QVector<Message> MessageWorker::getNewData() {
    QVector<Message> tmp = newData;
    newData.clear();
    m_dialog->setMessageCount(m_dialog->getMessageCount() + newData.size());
    return tmp;
}

void MessageWorker::stop()
{
    m_isWorking = false;
}
