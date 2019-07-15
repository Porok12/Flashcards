#include "contextrenderer.h"

ContextRenderer::ContextRenderer()
{
    changeState(TextRenderer::getInstance());
}

void ContextRenderer::render(BasicWidget *widget)
{
    if(Label* w = dynamic_cast<Label*>(widget)) {
        changeState(LabelRenderer::getInstance());
    }

    _state->render2(widget);
}

void ContextRenderer::changeState(Renderer* state)
{
    _state = state;
}
