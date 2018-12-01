#ifndef MESH_H
#define MESH_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

class Mesh : public QOpenGLFunctions
{
public:
    Mesh();
    ~Mesh();
    void loadMesh(int vertex[], int n);
protected:
    QOpenGLBuffer *vbo;
    QOpenGLVertexArrayObject *vao;
};

#endif // MESH_H
