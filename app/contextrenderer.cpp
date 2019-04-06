#include "contextrenderer.h"

ContextRenderer::ContextRenderer()
{
    changeState(TextRenderer::getInstance());
}

void ContextRenderer::draw(Graphic *graphic)
{
    _state->render(graphic);
}

void ContextRenderer::changeState(ContextRenderer::renderer_ptr state)
{
    _state = state;
}
