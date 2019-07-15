#include "fontfactory.h"

FontFactory* FontFactory::_instance = nullptr;
const char* FontFactory::FontTypeStr[] = {"R", "B", "RI", "BI"};

std::map<FontName, const char*> FontFactory::FontNameStr =
        boost::assign::map_list_of (UBUNTU, "Ubuntu") (UBUNTU_MONO, "UbuntuMono") (IPA, "ipa");

FontFactory::FontFactory()
{
    if(FT_Init_FreeType(&_library)) {
        qDebug() << "Unable to init FreeType";
    }

    for (int type = FONT_NONE; type <= (FONT_BOLD | FONT_ITALIC); type++) {
        loadFont(UBUNTU, static_cast<FontType>(type));
    }

    for (int type = FONT_NONE; type <= (FONT_BOLD | FONT_ITALIC); type++) {
        loadFont(UBUNTU_MONO, static_cast<FontType>(type));
    }

    loadFont(IPA, static_cast<FontType>(FONT_NONE));

    FT_Done_FreeType(_library);
}

void FontFactory::loadFont(FontName name, FontType type)
{
    _fonts.insert(std::make_pair(std::make_pair(name, type),
                                 Font(_library, getName(name, type))));
}

const char *FontFactory::getFontType(FontType type)
{
    return FontTypeStr[type];
}

std::string FontFactory::getName(FontName name, FontType type)
{
    string str = string(FontNameStr[name]) + "-" + string(getFontType(type)) + ".ttf";
    return str;
}

FontFactory::~FontFactory()
{
    FT_Done_FreeType(_library);
}

FontFactory *FontFactory::getInstance()
{
    if(_instance == nullptr) {
        _instance = new FontFactory();
    }

    return _instance;
}

Font *FontFactory::getFont(FontName name, FontType type)
{
    font_map::const_iterator it;
    if((it = _fonts.find(std::make_pair(name, type))) == _fonts.end()) {
        //_fonts.insert(std::make_pair(std::make_pair(name, type), Font(_library, getName(name, type))));
    }

    return const_cast<Font*>(&it->second);
}
