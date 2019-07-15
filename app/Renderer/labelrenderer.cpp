#include "labelrenderer.h"

LabelRenderer* LabelRenderer::_instance = nullptr;

LabelRenderer::LabelRenderer()
    : Renderer ()
{

}

LabelRenderer *LabelRenderer::getInstance()
{
    if(_instance == nullptr) {
        _instance = new LabelRenderer();
    }

    return _instance;
}

void LabelRenderer::render2(BasicWidget *label)
{
    _label = dynamic_cast<Label*>(label);
    if(_label != nullptr) {
        TextRenderer::getInstance()->setFont(IPA, FONT_NONE);
        TextRenderer::getInstance()->renderText(_label->text().c_str(), _label->x(), _label->y(), 0.6f);
        TextRenderer::getInstance()->setFont(UBUNTU);
    }
}
