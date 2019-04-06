#include "fontfactory.h"

FontFactory::FontFactory()
{
    FT_Error error;

    if((error = FT_Init_FreeType(&_library))) {
        // Handle Error
    }
}

FontFactory::~FontFactory()
{
    FT_Done_FreeType(_library);
}

const Font* FontFactory::createFont(string path)
{
    std::map<string, Font>::const_iterator it;
    if((it = _fonts.find(path)) == _fonts.end()) {
        _fonts.insert(std::pair<string, Font>(path, Font(_library, path)));
    }
    return &it->second;
}
