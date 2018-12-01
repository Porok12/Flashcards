#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <QString>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>

class ShaderProgram : public QOpenGLShaderProgram
{
public:
    ShaderProgram(QString name);
private:
    const QString dir = "/home/przemek/Projects/QtCreator/Flashcards/app";
};

#endif // SHADERPROGRAM_H
