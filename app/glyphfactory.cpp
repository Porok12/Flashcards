#include "glyphfactory.h"

GlyphFactory::GlyphFactory()
{
    for (int i = 0; i < NCHARCODES; i++) {
        _character[i] = nullptr;
    }
}

Character* GlyphFactory::getCharacter(char c)
{
    if(_character[c] == nullptr) {
        //_character[c] = new Character(c);
        newCharacter(c);
    }

    return _character[c];
}

void GlyphFactory::newCharacter(char c)
{
    //glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    /*if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
        // Handle error
        return;
    }

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    Character character = {
        texture,
        face->glyph->bitmap.width, face->glyph->bitmap.rows,
        face->glyph->bitmap_left, face->glyph->bitmap_top,
        face->glyph->advance.x
    };
    _character[c] = new Character(character);*/

    //glBindTexture(GL_TEXTURE_2D, 0);
}
