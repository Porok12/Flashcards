#ifndef MESSAGELOGGINGHANDLER_H
#define MESSAGELOGGINGHANDLER_H

#include <QTime>

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    FILE *pFile = fopen("logs.txt", "a+");
    QByteArray localMsg = msg.toLocal8Bit();
    QTime time = QTime::currentTime();
    QString formattedTime = time.toString("hh:mm:ss.zzz");
    QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();
    const char *file = context.file ? context.file : "";
    const char *function = context.function ? context.function : "";

    char buffer[256];
    sprintf(buffer, "(%s:%u) in '%s' - %s", file, context.line, function, localMsg.constData());

    switch (type) {
    case QtDebugMsg:
        fprintf(pFile, "[%-8.8s %s] %s\n", "Debug", formattedTimeMsg.constData(), buffer);
        break;
    case QtInfoMsg:
        fprintf(pFile, "[%-8.8s %s] %s\n", "Info", formattedTimeMsg.constData(), buffer);
        break;
    case QtWarningMsg:
        fprintf(pFile, "[%-8.8s %s] %s\n", "Warning", formattedTimeMsg.constData(), buffer);
        break;
    case QtCriticalMsg:
        fprintf(pFile, "[%-8.8s %s] %s\n", "Critical", formattedTimeMsg.constData(), buffer);
        break;
    case QtFatalMsg:
        fprintf(pFile, "[%-8.8s %s] %s\n", "Fatal", formattedTimeMsg.constData(), buffer);
        break;
    }
    fclose(pFile);
}

#endif // MESSAGELOGGINGHANDLER_H
