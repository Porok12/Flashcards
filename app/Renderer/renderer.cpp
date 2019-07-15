#include "renderer.h"

Renderer::~Renderer()
{
    delete vao;
    delete vbo;
    delete program;
}

void Renderer::render2(BasicWidget *widget)
{

}
