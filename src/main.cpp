#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQuickView>

#include "matrixmodel.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    /**--------------------------------------------------------------------------------------------------**/
    // new operator allocates memory from the heap and returns a pointer to the object in the memory
    /**--------------------------------------------------------------------------------------------------**/
    MatrixModel *model=new MatrixModel(4,4);
    QQmlApplicationEngine *engine=new QQmlApplicationEngine;
    
    // engine->rootContext returns an object to the qml engine's root context
    //QVariant::fromValue() is static function 
    engine->rootContext()->setContextProperty("game",QVariant::fromValue(model));
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
