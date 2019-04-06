#ifndef GLYPHCONTEXT_H
#define GLYPHCONTEXT_H


typedef int BTree;

class GlyphContext
{
public:
    GlyphContext();
    virtual ~GlyphContext();

    virtual void next(int step = 1);
    virtual void insert(int quantity = 1);

    virtual int* getFont();
    virtual void setFont(int*, int span = 1);
private:
    int _index;
    BTree* _fonts;
};

#endif // GLYPHCONTEXT_H
