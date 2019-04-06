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
#include "text.h"
#include "fontfactory.h"

class TextRenderer : public Renderer
{ 
private:
    typedef TextRenderer* rendererPointer; //typedef std::unique_ptr<TextRenderer> rendererPointer;

    void setupMesh();

    static rendererPointer _uniqueRenderer;
public:
    TextRenderer(); //TODO: make it private
    //~TextRenderer();

    static rendererPointer getInstance();

    void renderText(const char *text, float x, float y, int size);
    void render(Graphic*);
};

#endif // TEXTRENDERER_H
