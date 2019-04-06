#ifndef TEXT_H
#define TEXT_H

#include <string>
#include "graphic.h"
#include "font.h"

typedef std::string string;

class Text : public Graphic
{
public:
    Text();
    Text(string);
    Text(string, const Font*);

    string getText();
    const Font *getFont();

    float getSize() const;
    void setSize(float size);

    void setPosition(int, int);
    int getX() const;
    int getY() const;

private:
    string _text;
    const Font* _font;
    float _size;
    int _x, _y;
};

#endif // TEXT_H
