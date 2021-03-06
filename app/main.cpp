#include "mainwindow.h"
#include <QApplication>
#include <QSurfaceFormat>
#include "messagelogginghandler.h"

int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageOutput);

    QApplication a(argc, argv);

    QSurfaceFormat fmt;
    fmt.setSamples(4);
    fmt.setDepthBufferSize(24);
    fmt.setStencilBufferSize(8);
    fmt.setVersion(3, 3);
    //fmt.setProfile(QSurfaceFormat::CoreProfile);
    fmt.setProfile(QSurfaceFormat::OpenGLContextProfile::CompatibilityProfile);
    QSurfaceFormat::setDefaultFormat(fmt);

    MainWindow w;
    w.resize(800, 600);
    w.show();

    return a.exec();
}

