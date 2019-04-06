#ifndef FONT_H
#define FONT_H

#include <QOpenGLFunctions>

#include <string>
#include <ft2build.h>
#include FT_FREETYPE_H

typedef std::string string;

#include "character.h"

class Font
{
public:
    Font(FT_Library&, string);
    ~Font();

    void setSize(int width, int height);
    const FT_Face& getFace();

    Character* getCharacter(char);
private:    
    FT_Face _face;
    Character* _character[128];

    void createCharacter(char);
};

#endif // FONT_H
