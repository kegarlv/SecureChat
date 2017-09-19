#include "Backend.h"
#include <QApplication>
#include <QDebug>
#include <QInputDialog>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char **argv) {
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QString username;
    //    username = QInputDialog::getText(nullptr, "Enter username", "Enter username to login");
    username = "Ivan Voloshyn";
    Backend backend(username);

        QQmlApplicationEngine engine;
        qmlRegisterType<ContactList>("ContactList", 1, 0, "ContactList");
        qmlRegisterType<MessageList>("MessageList", 1, 0, "MessageList");
        qmlRegisterType<DialogController>("DialogController", 1, 0, "DialogController");

        qmlRegisterInterface<ContactList>("ContactList");
        qmlRegisterInterface<MessageList>("MessageList");
        qmlRegisterInterface<DialogController>("DialogController");

        engine.rootContext()->setContextProperty("backend", &backend);
        engine.load(QUrl(QStringLiteral("qrc:/ui/main.qml")));
        if (engine.rootObjects().isEmpty()) {
            return -1;
        }

        return app.exec();
}
