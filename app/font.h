#ifndef FONT_H
#define FONT_H

#include <QOpenGLFunctions>

#include <string>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "character.h"
#include "pathmanager.h"
#include <QtWidgets> //qDebug()

#define MAX_RANGE 128

class Font
{
public:
    Font(FT_Library&, std::string);
    ~Font();

    void setSize(int width, int height);
    Character* getCharacter(FT_ULong);
private:    
    FT_Face _face;
    Character* _character[MAX_RANGE];

    void loadCharacters();
    Character* createCharacter(FT_ULong);
};

#endif // FONT_H
