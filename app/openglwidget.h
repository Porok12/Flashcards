#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QtWidgets>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QObject>
#include <QTimer>

#include "shaderprogram.h"
#include "flashcardmesh.h"
#include "textrenderer.h"

#include <ft2build.h>
#include FT_FREETYPE_H

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    OpenGLWidget(QWidget *parent  = 0);
    ~OpenGLWidget();
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent *event) override;
private:
    FlashcardMesh* mesh;
    ShaderProgram *font, *program, *reverse;
    TextRenderer* textRenderer;

    QMatrix4x4 projection, model, view;

    QOpenGLFramebufferObject *fbo;
    GLuint texture;
    QOpenGLTexture *tex;
    QMatrix4x4 ortho;
    QTimer * timer;
};

#endif // OPENGLWIDGET_H
