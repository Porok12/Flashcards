#ifndef LABEL_H
#define LABEL_H

#include <string>
#include "basicwidget.h"

class Label : public BasicWidget
{
private:
    std::string _text;
public:
    Label();
    std::string text() const;
    void setText(const std::string &text);
};

#endif // LABEL_H
