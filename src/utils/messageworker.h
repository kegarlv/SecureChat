#ifndef MESSAGEWORKER_H
#define MESSAGEWORKER_H

#include <QObject>

#include "request.h"
#include "json.h"
#include "constants.h"

#include "src/structs/Dialog.h"

class MessageWorker : public QObject
{
    Q_OBJECT
public:
    MessageWorker(Dialog *dialog);

    //TODO add START AT
    QVector<Message> getNewData();

public slots:
    void doWork();
signals:
    void updateFinished();

private:
    Dialog *m_dialog = nullptr;
    QVector<Message> newData;
};

#endif // MESSAGEWORKER_H
