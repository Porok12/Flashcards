#ifndef BASICWIDGET_H
#define BASICWIDGET_H


class BasicWidget
{
private:
    int _x;
    int _y;
public:
    virtual ~BasicWidget();

    //virtual void draw() = 0;
    BasicWidget* setX(int x);
    BasicWidget* setY(int y);
    int x() const;
    int y() const;
};

#endif // BASICWIDGET_H
