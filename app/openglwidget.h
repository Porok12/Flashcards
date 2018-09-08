#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QtWidgets>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    OpenGLWidget(QWidget *parent  = 0);
    ~OpenGLWidget();
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent *event) override;
private:
    QOpenGLShaderProgram *program, *reverse;
    QOpenGLBuffer *vbo;
    QOpenGLVertexArrayObject *vao;
    QMatrix4x4 projection, model, view;

    QOpenGLFramebufferObject *fbo;
    QPainter *painter;
};

#endif // OPENGLWIDGET_H
