#include "DialogController.h"

DialogController::DialogController(int dialogId) {
    m_dialog = new Dialog(dialogId);
}

DialogController::DialogController() {
    fb = new Firebase("https://securechat-4276e.firebaseio.com/Dialogs/1");
    connect(fb, &Firebase::newEvent, this, &DialogController::newEvent);
};

DialogController::~DialogController() {
    delete fb;
}

int DialogController::getDialogID() {
    return m_dialog != nullptr ? m_dialog->getDialogId() : -1;
}

void DialogController::setDialogID(int dialogID) {
    delete m_dialog;
    m_dialog = new Dialog(dialogID);
}

void DialogController::startUpdating() {
    fb->listenForEvents();
    qDebug() << "Start updating";
}

MessageList *DialogController::getMessageList() {
    //TODO FAKITOL
    if (m_dialog != nullptr) {
        startUpdating();
    }
    return m_dialog->getMessageList();
}

void DialogController::sendMessage(const QString &messageText) {
    //TODO update username
    Message msg(messageText, "Ivan Voloshyn");
    QString requestUrl = DIALOG_URL + QString::number(m_dialog->getDialogId()) + "/messages.json";
    Request::post(requestUrl, msg.toJson());
}

void DialogController::updateFinished() {
}

void DialogController::newEvent(FirebaseEvent e) {
    if(e.type == "put") {
        qDebug() << "New messages";
        //TODO parseMessage
        QString s = ((e.data.remove(0,36)).replace(0,1,'{'));
        s.chop(4);
        QJsonDocument doc;
        QJsonParseError err;
        doc.fromJson(s.toUtf8(), &err);
        qDebug() << err.errorString();
        qDebug() << doc.object();
        qDebug() << s;
    } else {
        qDebug() << "Keep-alive";
    }
}
