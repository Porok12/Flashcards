#ifndef CHARACTER_H
#define CHARACTER_H

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QVector2D>

class Character
{
public:
    Character(char);

    GLuint textureID() const;
    void setTextureID(const GLuint &textureID);

    int width() const;
    void setWidth(int width);

    int height() const;
    void setHeight(int height);

    int xBearing() const;
    void setXBearing(int xBearing);

    int yBearing() const;
    void setYBearing(int yBearing);

    GLuint advance() const;
    void setAdvance(const GLuint advance);

private:
    char _charcode;

    GLuint _textureID;
    int _width, _height;
    int _xBearing, _yBearing;
    GLuint _advance;
};

#endif // CHARACTER_H
