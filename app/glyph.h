#ifndef GLYPH_H
#define GLYPH_H

#include "glyphcontext.h"

typedef int Window;

class Glyph
{
public:
    virtual ~Glyph();

    virtual void draw(Window*, GlyphContext&);

    virtual void setFont(int*, GlyphContext&);
    virtual int* getFont(GlyphContext&);
    virtual void first(GlyphContext&);
    virtual void next(GlyphContext&);
    virtual void isDone(GlyphContext&);
    virtual Glyph* current(GlyphContext&);

    virtual void insert(Glyph*, GlyphContext&);
    virtual void remove(GlyphContext&);
protected:
    Glyph();
};

#endif // GLYPH_H
