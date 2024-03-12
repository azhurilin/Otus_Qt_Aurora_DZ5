#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "DZ5_client.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


    client c;
    engine.rootContext()->setContextObject(&c);
  //  engine.rootContext()->setContextProperty(updateTestEditor   ,slotReadyRead());
  //  QObject::connect(c, SIGNAL(slotReadyRead()), root, SLOT(updateTestEditor()));




    engine.load(url);

    return app.exec();
}
