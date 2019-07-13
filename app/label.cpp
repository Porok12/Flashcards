#include "label.h"

Label::Label()
{
    _text = "Test!";
}

Label::Label(std::string text)
    : _text(text)
{

}

std::string Label::text() const
{
    return _text;
}

void Label::setText(const std::string &text)
{
    _text = text;
}

