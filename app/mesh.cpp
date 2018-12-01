#include "mesh.h"

Mesh::Mesh()
{
    /*
    vao = new QOpenGLVertexArrayObject;
    vao->create();
    vao->bind();
    vbo = new QOpenGLBuffer;
    vbo->setUsagePattern(QOpenGLBuffer::DynamicDraw);
    vbo->create();
    vbo->bind();
    vbo->allocate(4 * 6 * sizeof(float));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);

    //

    vao = new QOpenGLVertexArrayObject;
    vao->create();
    vao->bind();
    vbo = new QOpenGLBuffer;
    vbo->create();
    vbo->bind();
    static const float vertices[] = {
            -0.5f, -0.5f, 0.0f, 0.0f,  0.0f,
             0.5f, -0.5f, 0.0f, 1.0f,  0.0f,
             0.5f,  0.5f, 0.0f, 1.0f,  1.0f,
            -0.5f,  0.5f, 0.0f, 0.0f,  1.0f
    };
    vbo->allocate(vertices, sizeof(vertices));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float)));
    vbo->release();
    vao->release();
    */
}

Mesh::~Mesh()
{
    delete vbo;
    delete vao;
}

void Mesh::loadMesh(int vertex[], int n)
{

}

/*
void Mesh::setupMesh()
{

}
*/
