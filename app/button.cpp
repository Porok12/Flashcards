#include "button.h"

Button::Button()
{
    add(new Text("Button"));
    add(new Ractangle(100, 200));
}

void Button::add(Graphic* graphic)
{
    _graphics.push_back(graphic);
}
