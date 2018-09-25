#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QtWidgets>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <ft2build.h>
#include FT_FREETYPE_H

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
    QOpenGLShaderProgram *program, *reverse, *font;
    QOpenGLBuffer *vbo;
    QOpenGLVertexArrayObject *vao;
    QMatrix4x4 projection, model, view;

    QOpenGLFramebufferObject *fbo;
    QPainter *painter;
    GLuint texture;
    QOpenGLTexture *tex;
    void renderText(const char * text, float x, float y, int size);
    QOpenGLBuffer *fontVbo;
    QOpenGLVertexArrayObject *fontVao;
    FT_Face face;
    QMatrix4x4 ortho;
};

#endif // OPENGLWIDGET_H
