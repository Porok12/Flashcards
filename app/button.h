#ifndef BUTTON_H
#define BUTTON_H

#include <vector>
#include "graphic.h"
#include "text.h"
#include "ractangle.h"

typedef std::vector<Graphic*> vector;

class Button : public Graphic
{
public:
    Button();

    virtual void add(Graphic*);
private:
    vector _graphics;
};

#endif // BUTTON_H
