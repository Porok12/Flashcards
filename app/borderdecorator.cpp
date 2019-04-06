#include "borderdecorator.h"

BorderDecorator::BorderDecorator(VisualComponent *component, int width)
    : Decorator (component)
{
    _width = width;
}

void BorderDecorator::draw()
{
    Decorator::draw();
    drawBorder();
}

void BorderDecorator::drawBorder()
{

}
