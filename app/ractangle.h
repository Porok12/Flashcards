#ifndef RACTANGLE_H
#define RACTANGLE_H

#include <utility>
#include "graphic.h"

//typedef std::pair<int, int> vec2;

class Ractangle : public Graphic
{
public:
    Ractangle(int width, int height);
private:
    int _width;
    int _height;
};

#endif // RACTANGLE_H
