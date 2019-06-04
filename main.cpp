#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include <QQuickStyle>
#include <QIcon>
#include "treemodel.h"
//#include "nic.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication::setApplicationName("EtherCAT");
    QGuiApplication::setOrganizationName("NEXGOL");
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QGuiApplication app(argc, argv);



    QIcon::setThemeName("QmlBackNetWork");

    QQmlApplicationEngine engine;

//    TableViewModel model;
//    model.Add(QStringLiteral("657"),QStringLiteral("8789"),QStringLiteral("dfgbsdfs"));

//    engine.rootContext()->setContextProperty("tabviewmodel",&model);

//    qmlRegisterType<NIC>("nic_setup",1,0,"nic_info");

    treemodel model;
    engine.rootContext()->setContextProperty("mytreeview",&model);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
