#include <QCoreApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQuickView>

#include "matrixmodel.h"

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    MatrixModel *model=new MatrixModel(4,4);
    QQmlApplicationEngine *engine=new QQmlApplicationEngine;
    engine->rootContext()->setContextProperty("game",QVariant::fromValue(model));
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
