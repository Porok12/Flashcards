#ifndef FLASHCARD_H
#define FLASHCARD_H

#include <QString>
#include <string>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLTexture>

using namespace std;

/*struct side
{
    string word;
    string pron;
    string example;
    QOpenGLTexture image;
    string tag;
};
*/

class Flashcard
{
public:
    Flashcard();
    QString word;
    QString translation;
    //void flip();
private:
    //side obverse;
    //side reverse;

};

#endif // FLASHCARD_H
