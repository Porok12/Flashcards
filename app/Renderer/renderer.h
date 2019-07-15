#ifndef RENDERER_H
#define RENDERER_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <memory>

#include "shaderprogram.h"
#include "basicwidget.h"

class Renderer : public QOpenGLFunctions
{
public:
    virtual ~Renderer();

    QMatrix4x4 ortho;

    virtual void render2(BasicWidget*);
protected:
    QOpenGLVertexArrayObject* vao;
    QOpenGLBuffer* vbo;
    ShaderProgram* program;
};

#endif // RENDERER_H
