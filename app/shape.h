#ifndef SHAPE_H
#define SHAPE_H

//Wzorzec Adapter
class Shape
{
public:
    Shape();

    bool boundingBox();
private:
    int _width;
    int _height;
};

#endif // SHAPE_H
