#include "request.h"

Request::Request() {
}

QString Request::post(const QString &url, const QString &data) {
    QNetworkAccessManager manager;
    QString response;
    QEventLoop loop;
    connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    connect(&manager, &QNetworkAccessManager::finished, [&](QNetworkReply *reply) {
        response = reply->readAll();
    });

    QNetworkRequest request = QNetworkRequest(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    manager.post(request, data.toUtf8());
    loop.exec();
    return response;
}

QString Request::get(const QString &url) {
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
