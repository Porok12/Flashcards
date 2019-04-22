#include "textrenderer.h"

TextRenderer::TextRenderer()
{
    initializeOpenGLFunctions();
    setupMesh();

    program = new ShaderProgram("font");
    program->setUniformValue("texture", 0);
}

/*TextRenderer::~TextRenderer()
{
    delete vao;
    delete vbo;
    delete program;
}*/

TextRenderer* TextRenderer::_uniqueRenderer = nullptr;

TextRenderer* TextRenderer::getInstance()
{
    if(_uniqueRenderer == nullptr) {
        _uniqueRenderer = new TextRenderer();
    }

    return _uniqueRenderer;
}

void TextRenderer::setupMesh()
{
    vao = new QOpenGLVertexArrayObject;
    vao->create();
    vao->bind();
    vbo = new QOpenGLBuffer;
    vbo->setUsagePattern(QOpenGLBuffer::DynamicDraw);
    vbo->create();
    vbo->bind();
    vbo->allocate( 4 * 6 * sizeof(float) );

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);

    vbo->release();
    vao->release();

    _font = FontFactory::getInstance()->getFont(UBUNTU);
}

void TextRenderer::setFont(FontName name, FontType type)
{
    _font = FontFactory::getInstance()->getFont(name, type);
}

/*
void TextRenderer::renderText(const char *text, float x, float y, int size)
{
    FT_Library ft;
    if(FT_Init_FreeType(&ft)) {
      fprintf(stderr, "Could not init freetype library\n");
      return ;
    }

    FT_Face face;
    if(FT_New_Face(ft, "/home/przemek/Projects/QtCreator/Flashcards/app/Ubuntu.ttf", 0, &face)) {
      fprintf(stderr, "Could not open font\n");
      return ;
    }

    FT_Set_Pixel_Sizes(face, 0, 96);

    const char *ptr;
    FT_GlyphSlot g = face->glyph;

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    program->bind();
    program->setUniformValue(program->uniformLocation("projection"), this->ortho);
    vao->bind();
    glActiveTexture(GL_TEXTURE0);

    for(ptr = text; *ptr; ptr++)
    {
        if(FT_Load_Char(face, *ptr, FT_LOAD_RENDER))
            continue;

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, g->bitmap.width, g->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, g->bitmap.buffer);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        float x2 = x + g->bitmap_left * size;
        float y2 = y - (g->bitmap.rows - g->bitmap_top) * size;
        float w = g->bitmap.width * size;
        float h = g->bitmap.rows * size;

        GLfloat box[] = {
            x2,     y2 + h, 0.0f, 0.0f,
            x2,     y2    , 0.0f, 1.0f,
            x2 + w, y2    , 1.0f, 1.0f,
            x2,     y2 + h, 0.0f, 0.0f,
            x2 + w, y2    , 1.0f, 1.0f,
            x2 + w, y2 + h, 1.0f, 0.0f
        };

        vbo->bind();
        vbo->write(0, box, sizeof(box));
        glDrawArrays(GL_TRIANGLES, 0, 6);
        vbo->release();

        x += (g->advance.x >> 6) * size;
        y += (g->advance.y >> 6) * size;
    }
    vao->release();
    program->release();
}
*/
void TextRenderer::renderText2(const char *text, float x, float y, float size)
{
    const char *ptr;

    program->bind();
    program->setUniformValue(program->uniformLocation("projection"), this->ortho);
    vao->bind();
    glActiveTexture(GL_TEXTURE0);

    for(ptr = text; *ptr; ptr++)
    {
        Character* ch = _font->getCharacter(*ptr);
        if(ch == nullptr) {
            continue;
        }

        float x2 = x + ch->xBearing() * size;
        float y2 = y - (ch->height() - ch->yBearing()) * size;
        float w = ch->width() * size;
        float h = ch->height() * size;

        GLfloat box[] = {
            x2,     y2 + h, 0.0f, 0.0f,
            x2,     y2    , 0.0f, 1.0f,
            x2 + w, y2    , 1.0f, 1.0f,
            x2,     y2 + h, 0.0f, 0.0f,
            x2 + w, y2    , 1.0f, 1.0f,
            x2 + w, y2 + h, 1.0f, 0.0f
        };

        glBindTexture(GL_TEXTURE_2D, ch->textureID());

        vbo->bind();
        vbo->write(0, box, sizeof(box));
        glDrawArrays(GL_TRIANGLES, 0, 6);
        vbo->release();

        x += (ch->advance() >> 6) * size;
    }
    vao->release();
    program->release();
}
