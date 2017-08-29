#ifndef REQUEST_H
#define REQUEST_H

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <QString>

class Request : public QObject
{
    Q_OBJECT
    Request();
public:
    static QString get(QString url);
};

#endif // REQUEST_H
