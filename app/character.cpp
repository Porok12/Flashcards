#include "character.h"

Character::Character(char c)
{
    _charcode = c;
}

int Character::yBearing() const
{
    return _yBearing;
}

void Character::setYBearing(int yBearing)
{
    _yBearing = yBearing;
}

int Character::xBearing() const
{
    return _xBearing;
}

void Character::setXBearing(int xBearing)
{
    _xBearing = xBearing;
}

GLuint Character::textureID() const
{
    return _textureID;
}

void Character::setTextureID(const GLuint &textureID)
{
    _textureID = textureID;
}

int Character::width() const
{
    return _width;
}

void Character::setWidth(int width)
{
    _width = width;
}

int Character::height() const
{
    return _height;
}

void Character::setHeight(int height)
{
    _height = height;
}

GLuint Character::advance() const
{
    return _advance;
}

void Character::setAdvance(const GLuint advance)
{
    _advance = advance;
}
