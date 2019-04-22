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
        TextRenderer::getInstance()->setFont(UBUNTU, FONT_ITALIC);
        TextRenderer::getInstance()->renderText2(_label->text().c_str(), 200, 300, 0.6f);
        TextRenderer::getInstance()->setFont(UBUNTU_MONO, FONT_BOLD | FONT_ITALIC);
        TextRenderer::getInstance()->renderText2(_label->text().c_str(), 200, 390, 0.6f);
        TextRenderer::getInstance()->setFont(UBUNTU);
    }
}
