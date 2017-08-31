#ifndef MESSAGEWORKER_H
#define MESSAGEWORKER_H

#include <QObject>

#include "messagelist.h"
#include "request.h"
#include "libs/json.h"
#include <unistd.h>
#include "Dialog.h"

class MessageWorker : public QObject
{
    Q_OBJECT
public:
    MessageWorker(MessageList *messageList);

    QVector<Message> getNewData();

public slots:
    void doWork();
signals:
    void updateFinished();

private:
    MessageList *m_messageList;
    QVector<Message> newData;
};

#endif // MESSAGEWORKER_H
