#ifndef CONTEXTRENDERER_H
#define CONTEXTRENDERER_H

#include <memory>

#include "graphic.h"
#include "renderer.h"
#include "textrenderer.h"

class ContextRenderer
{
private:
    typedef Renderer* renderer_ptr;
    renderer_ptr _state;

    void changeState(renderer_ptr);
public:
    ContextRenderer();

    void draw(Graphic*);
};

#endif // CONTEXTRENDERER_H
