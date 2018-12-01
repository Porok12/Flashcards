#ifndef FLASHCARDMESH_H
#define FLASHCARDMESH_H

#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <QtWidgets>
#include <QObject>

//: public QOpenGLFunctions
class FlashcardMesh : public QOpenGLFunctions
{
public:
    FlashcardMesh();
    ~FlashcardMesh();
    void draw();
private:
    void setupMesh();
    QOpenGLVertexArrayObject *vao;
    QOpenGLBuffer *vbo;
};

#endif // FLASHCARDMESH_H
