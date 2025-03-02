#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "translatehelper.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    TranslateHelper translateHelper(app, engine);
    engine.rootContext()->setContextProperty("translateHelper", &translateHelper);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("BasicMultilingualApp", "Main");

    return app.exec();
}
