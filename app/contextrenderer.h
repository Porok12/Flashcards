#ifndef CONTEXTRENDERER_H
#define CONTEXTRENDERER_H

#include <memory>

#include "renderer.h"
#include "textrenderer.h"
#include "labelrenderer.h"
#include "basicwidget.h"

class ContextRenderer
{
private:
    Renderer* _state;

    void changeState(Renderer*);
public:
    ContextRenderer();

    void render(BasicWidget* widget);
};

#endif // CONTEXTRENDERER_H
