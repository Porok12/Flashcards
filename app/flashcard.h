#ifndef FLASHCARD_H
#define FLASHCARD_H

#include <QString>
#include <string>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLTexture>

using namespace std;

class Flashcard
{
public:
    Flashcard();
    QString word;
    QString translation;
private:
};

#endif // FLASHCARD_H
