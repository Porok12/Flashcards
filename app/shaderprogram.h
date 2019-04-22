#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <QString>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>

#include "pathmanager.h"

class ShaderProgram : public QOpenGLShaderProgram
{
public:
    ShaderProgram(QString name);
private:
    const QString dir = PathManager::getInstance()->getPath(SHADERS_PATH).c_str();
};

#endif // SHADERPROGRAM_H
