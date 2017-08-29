#include "request.h"

Request::Request()
{

}

QString Request::get(QString url)
{
    QNetworkAccessManager manager;
    QString response;
    QEventLoop loop;
    connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    connect(&manager, &QNetworkAccessManager::finished, [&](QNetworkReply *reply) {
        response = reply->readAll();
    });
    manager.get(QNetworkRequest(QUrl(url)));
    loop.exec();
    return response;
}
