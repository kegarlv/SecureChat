#include <iostream>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Backend.h"


int main(int argc, char **argv) {
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    Backend backend;
    backend.setUsername("kegarlv");
    backend.authorize();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("backend",&backend);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if(engine.rootObjects().isEmpty()) {
        return -1;
    }
    return app.exec();
}
