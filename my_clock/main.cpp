#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "currenttime.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/my_clock/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    qmlRegisterType<CurrentTime>("currenttime.h", 1, 0, "CurrentTime");

    engine.load(url);


    return app.exec();
}
