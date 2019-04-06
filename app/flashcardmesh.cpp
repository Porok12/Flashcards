#include "flashcardmesh.h"

FlashcardMesh::FlashcardMesh()
{
    initializeOpenGLFunctions();
    setupMesh();
}

FlashcardMesh::~FlashcardMesh()
{

}

void FlashcardMesh::draw()
{
    vao->bind();
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    vao->release();
}

void FlashcardMesh::setupMesh()
{
    vao = std::unique_ptr<QOpenGLVertexArrayObject>(new QOpenGLVertexArrayObject);
    vao->create();
    vao->bind();
    vbo = std::unique_ptr<QOpenGLBuffer>(new QOpenGLBuffer);
    vbo->create();
    vbo->bind();
    static const float vertices[] = {
            -0.8f, -0.5f, 0.0f, 0.0f,  0.0f,
             0.8f, -0.5f, 0.0f, 1.0f,  0.0f,
             0.8f,  0.5f, 0.0f, 1.0f,  1.0f,
            -0.8f,  0.5f, 0.0f, 0.0f,  1.0f
    };
    vbo->allocate(vertices, 20 * sizeof(float));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float)));
    vbo->release();
}
