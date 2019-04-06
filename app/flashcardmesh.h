#ifndef FLASHCARDMESH_H
#define FLASHCARDMESH_H

#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <QtWidgets>
#include <QObject>

class FlashcardMesh : public QOpenGLFunctions
{
public:
    FlashcardMesh();
    ~FlashcardMesh();
    void draw();
private:
    void setupMesh();
    std::unique_ptr<QOpenGLVertexArrayObject> vao;
    std::unique_ptr<QOpenGLBuffer> vbo;
};

#endif // FLASHCARDMESH_H
