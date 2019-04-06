#ifndef GLYPHFACTORY_H
#define GLYPHFACTORY_H

#include <map>
#include "character.h"

const int NCHARCODES = 128;

class GlyphFactory
{
public:
    GlyphFactory();
    virtual Character* getCharacter(char);
private:
    Character* _character[NCHARCODES];

    void newCharacter(char c);
};

#endif // GLYPHFACTORY_H
