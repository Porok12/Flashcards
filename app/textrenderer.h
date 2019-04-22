#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "renderer.h"
#include "shaderprogram.h"
#include "fontfactory.h"

class TextRenderer : public Renderer//<TextRenderer>
{ 
private:
    TextRenderer();
    void setupMesh();

    static TextRenderer* _uniqueRenderer;
public:
    //~TextRenderer();
    Font* _font;

    static TextRenderer* getInstance();

    //void renderText(const char *text, float x, float y, int size);
    void renderText2(const char *text, float x, float y, float size);
    void setFont(FontName name, FontType type = FONT_NONE);
};

#endif // TEXTRENDERER_H
