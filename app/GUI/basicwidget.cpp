#include "basicwidget.h"

BasicWidget* BasicWidget::setX(int x)
{
    _x = x;
    return this;
}

BasicWidget* BasicWidget::setY(int y)
{
    _y = y;
    return this;
}

int BasicWidget::x() const
{
    return _x;
}

int BasicWidget::y() const
{
    return _y;
}

BasicWidget::~BasicWidget()
{
    _x = 0;
    _y = 0;
}
