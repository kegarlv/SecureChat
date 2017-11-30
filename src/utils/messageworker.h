#ifndef MESSAGEWORKER_H
#define MESSAGEWORKER_H

#include <QObject>

#include "request.h"
#include "json.h"
#include "constants.h"

#include "src/structs/Dialog.h"
#include "src/utils/restfirebaseapi.h"
#include "QJsonArray"

/**
 * @brief The MessageWorker class
 * After creation, automaticly starts fetching data for certain dialog
 * To properly delete object trigger stop() function and handle endUpdating() signal
 */
class MessageWorker : public QObject
{
    Q_OBJECT
public:
    MessageWorker(Dialog *dialog);
    ~MessageWorker();

    //TODO add START AT
    QVector<Message> getNewData();

    void stop();

public slots:
    void doWork();

signals:
    void updateFinished();
    void endUpdating();

private:
    bool m_isWorking = true;
    Dialog *m_dialog = nullptr;
    QVector<Message> newData;
    FirebaseAPI *m_firebaseApi = nullptr;
};

#endif // MESSAGEWORKER_H
