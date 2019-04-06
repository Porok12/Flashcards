#include "text.h"

Text::Text()
    : Text("")
{
    _size = 1.0f;
}

Text::Text(string text)
    : _text(text), _font(nullptr)
{

}

Text::Text(string text, const Font* font)
    : _text(text), _font(font)
{

}

const Font *Text::getFont()
{
    return _font;
}

float Text::getSize() const
{
    return _size;
}

void Text::setSize(float size)
{
    _size = size;
}

void Text::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

int Text::getX() const
{
    return _x;
}

int Text::getY() const
{
    return _y;
}

string Text::getText()
{
    return _text;
}
