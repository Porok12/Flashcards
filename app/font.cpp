#include "font.h"

Font::Font(FT_Library &library, string path)
{
    for (int i = 0; i < 128; i++) {
        _character[i] = nullptr;
    }

    FT_Error error;
    error = FT_New_Face(library, path.c_str(), 0, &_face);

    if(error == FT_Err_Unknown_File_Format) {
      // Handle Error
    }
    else if(error) {
      // Handle Error
    }

    setSize(0, 96);
}

Font::~Font()
{
    FT_Done_Face(_face);
}

void Font::setSize(int width, int height)
{
    FT_Error error;
    if((error = FT_Set_Pixel_Sizes(_face, static_cast<FT_UInt>(width), static_cast<FT_UInt>(height)))) {
        // Handle error
    }
}

const FT_Face& Font::getFace()
{
    return _face;
}

Character *Font::getCharacter(char c)
{
    if(_character[c] == nullptr) {
        createCharacter(c);
    }
    return _character[c];
}

void Font::createCharacter(char c)
{
    Character* ch = new Character(c);

    GLuint texture;
    /*glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED,
        _face->glyph->bitmap.width,
        _face->glyph->bitmap.rows,
        0, GL_RED, GL_UNSIGNED_BYTE,
        _face->glyph->bitmap.buffer);*/

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //ch->setTextureID(texture);
    ch->setWidth(_face->glyph->bitmap.width);
    ch->setHeight(_face->glyph->bitmap.rows);
    ch->setXBearing(_face->glyph->bitmap_left);
    ch->setYBearing(_face->glyph->bitmap_top);
    ch->setAdvance(_face->glyph->advance.x);

    //_character[c] = ch;
}

/*Character *Font::getCharacter(char c)
{
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    if (FT_Load_Char(_face, c, FT_LOAD_RENDER)) {
        //std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
        return new Character('?');
    }

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, _face->glyph->bitmap.width,
        _face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE,
        _face->glyph->bitmap.buffer );

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return new Character('?');
}*/
