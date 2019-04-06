#ifndef FONTFACTORY_H
#define FONTFACTORY_H

#include <string>
#include <map>

#include "font.h"

class FontFactory
{
public:
    FontFactory();
    ~FontFactory();

    const Font* createFont(string);
private:
    FT_Library _library;
    std::map<string, Font> _fonts;
};

#endif // FONTFACTORY_H
