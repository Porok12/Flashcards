#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "shaderprogram.h"

class TextRenderer : public QOpenGLFunctions
{
public:
    TextRenderer();
    ~TextRenderer();

    QMatrix4x4 ortho;

    void renderText(const char *text, float x, float y, int size);
private:
    QOpenGLVertexArrayObject* vao;
    QOpenGLBuffer* vbo;
    ShaderProgram* program;

    void setupMesh();
};

#endif // TEXTRENDERER_H
