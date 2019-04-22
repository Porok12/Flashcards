#ifndef LABELRENDERER_H
#define LABELRENDERER_H

#include "renderer.h"
#include "label.h"
#include "textrenderer.h"

class LabelRenderer : public Renderer//<LabelRenderer>
{
private:
    LabelRenderer();
    static LabelRenderer* _instance;

    Label* _label;
public:
    static LabelRenderer* getInstance();

    void render2(BasicWidget*);
};

#endif // LABELRENDERER_H
