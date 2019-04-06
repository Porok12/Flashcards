#include "renderer.h"

Renderer::~Renderer()
{
    delete vao;
    delete vbo;
    delete program;
}

void Renderer::render(Graphic *graphic)
{
    if(dynamic_cast<Text*>(graphic) != nullptr) {

    }
}
