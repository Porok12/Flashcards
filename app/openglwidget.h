#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QtWidgets>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class OpenGLWidget : public QOpenGLWidget, QOpenGLFunctions
{
public:
    OpenGLWidget(QWidget *parent  = 0);
    ~OpenGLWidget();
protected:
    void initializeGL();
    void resieGL(int w, int h);
    void paintGL();
private:
    QOpenGLShaderProgram *program;
    QOpenGLBuffer *vbo;
    QOpenGLVertexArrayObject *vao;
};

#endif // OPENGLWIDGET_H
