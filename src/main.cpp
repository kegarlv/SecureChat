#include <iostream>

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QInputDialog>
#include "Backend.h"

int main(int argc, char **argv) {
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QString username = QInputDialog::getText(nullptr, "Enter username","Enter username to login");

    Backend backend(username);
    backend.authorize();

    QQmlApplicationEngine engine;
    qmlRegisterType<ContactModel>("ContactModel", 1, 0, "ContactModel");
    qmlRegisterType<MessageList>("MessageList", 1, 0, "MessageList");

    qmlRegisterInterface<ContactModel>("ContactModel");
    qmlRegisterInterface<MessageList>("MessageList");

    engine.rootContext()->setContextProperty("backend",&backend);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if(engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
