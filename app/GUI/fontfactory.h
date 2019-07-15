#ifndef FONTFACTORY_H
#define FONTFACTORY_H

#include <string>
#include <map>
#include <vector>
#include <memory>

#include "font.h"
#include "boost/assign.hpp"

typedef std::string string;

enum FontType {
    FONT_NONE = 0,
    FONT_BOLD = 1,
    FONT_ITALIC = 2
};

inline FontType operator|(FontType a, FontType b) {
    return static_cast<FontType>(static_cast<int>(a) | static_cast<int>(b));
}

enum FontName {
    UBUNTU,
    UBUNTU_MONO,
    IPA
};

class FontFactory
{
public:
    static const char* FontTypeStr[];
    const char* getFontType(FontType type);

    std::string getName(FontName name, FontType type);

    static std::map<FontName, const char*> FontNameStr;

    ~FontFactory();

    static FontFactory* getInstance();
    Font* getFont(FontName name, FontType type = FONT_NONE);
private:
    FontFactory();
    static FontFactory* _instance;

    FT_Library _library;
    typedef std::pair<FontName, FontType> font_pair;
    typedef  std::map<font_pair, Font> font_map;
    font_map _fonts;

    void loadFont(FontName name, FontType type = FONT_NONE);
};

#endif // FONTFACTORY_H
