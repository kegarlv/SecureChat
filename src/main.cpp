#include "src/controllers/ContactController.h"
#include "src/controllers/DialogController.h"
#include <QApplication>
#include <QDebug>
#include <QInputDialog>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "src/utils/restfirebaseapi.h"
#include <QBuffer>

int main(int argc, char **argv) {
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<Message>("Message", 1, 0, "Message");
    qmlRegisterType<ContactList>("ContactList", 1, 0, "ContactList");
    qmlRegisterType<MessageList>("MessageList", 1, 0, "MessageList");
    qmlRegisterType<UserController>("UserController", 1, 0, "UserController");
    qmlRegisterType<DialogController>("DialogController", 1, 0, "DialogController");
    qmlRegisterType<ContactController>("ContactController", 1, 0, "ContactController");

    qmlRegisterInterface<Message>("Message");
    qmlRegisterInterface<ContactList>("ContactList");
    qmlRegisterInterface<MessageList>("MessageList");
    qmlRegisterInterface<UserController>("UserController");
    qmlRegisterInterface<DialogController>("DialogController");
    qmlRegisterInterface<ContactController>("ContactController");

    engine.load(QUrl(QStringLiteral("qrc:/ui/LoginPage.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
