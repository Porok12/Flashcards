#include "shaderprogram.h"

ShaderProgram::ShaderProgram(QString name)
{
    QOpenGLShader vertexShader(QOpenGLShader::Vertex, this);
    vertexShader.compileSourceFile(dir + name + ".vert");
    QOpenGLShader fragmentShader(QOpenGLShader::Fragment, this);
    fragmentShader.compileSourceFile(dir + name + ".frag");
    this->addShader(&vertexShader);
    this->addShader(&fragmentShader);
    this->link();
    this->bind();
}
