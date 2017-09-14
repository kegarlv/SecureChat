#ifndef MESSAGEWORKER_H
#define MESSAGEWORKER_H

#include <QObject>

#include "request.h"
#include "json.h"
#include "constants.h"
#include "src/models/messagelist.h"

class MessageWorker : public QObject
{
    Q_OBJECT
public:
    MessageWorker(MessageList *messageList, int m_dialogId);

    //TODO add START AT
    QVector<Message> getNewData();

public slots:
    void doWork();
signals:
    void updateFinished();

private:
    MessageList *m_messageList;
    QVector<Message> newData;
    int m_dialogId;
};

#endif // MESSAGEWORKER_H
