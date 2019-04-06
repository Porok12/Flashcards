#ifndef GRAPHIC_H
#define GRAPHIC_H


class Graphic
{
public:
    Graphic();

    virtual void add(Graphic*);
    virtual void draw();

    virtual ~Graphic();
};

#endif // GRAPHIC_H
