#include "glyph.h"

Glyph::~Glyph()
{

}

void Glyph::draw(Window *, GlyphContext &)
{

}

void Glyph::setFont(int *, GlyphContext &)
{

}

int *Glyph::getFont(GlyphContext &)
{
    return new int;
}

void Glyph::first(GlyphContext &)
{

}

void Glyph::next(GlyphContext &)
{

}

void Glyph::isDone(GlyphContext &)
{

}

Glyph *Glyph::current(GlyphContext &)
{
    return nullptr;
}

void Glyph::insert(Glyph *, GlyphContext &)
{

}

void Glyph::remove(GlyphContext &)
{

}

Glyph::Glyph()
{

}
