#include "label.h"

Label::Label()
{
    _text = "Test!";
}

std::string Label::text() const
{
    return _text;
}

void Label::setText(const std::string &text)
{
    _text = text;
}

