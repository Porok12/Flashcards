#include "textrenderer.h"

TextRenderer::TextRenderer()
{
    initializeOpenGLFunctions();
    setupMesh();

    program = new ShaderProgram("font");
    program->setUniformValue("texture", 0);
}

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

void TextRenderer::renderText(const char *text, float x, float y, float size)
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
