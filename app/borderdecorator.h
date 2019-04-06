#ifndef BORDERDECORATOR_H
#define BORDERDECORATOR_H

#include "decorator.h"

class BorderDecorator : public Decorator
{
public:
    BorderDecorator(VisualComponent* component, int width);

    virtual void draw();
private:
    virtual void drawBorder();
    int _width;
};

#endif // BORDERDECORATOR_H
