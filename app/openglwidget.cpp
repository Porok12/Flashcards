#include "openglwidget.h"

#include <QOpenGLShaderProgram>

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent), program(nullptr)
{

}

OpenGLWidget::~OpenGLWidget()
{
    delete program;
    delete vao;
    delete vbo;
}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    QOpenGLShader *vShader = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vShader->compileSourceFile("/home/przemek/Projects/QtCreator/Flashcards/app/flashcard.vert");

    QOpenGLShader *fShader = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fShader->compileSourceFile("/home/przemek/Projects/QtCreator/Flashcards/app/flashcard.frag");

    program = new QOpenGLShaderProgram;
    program->addShader(vShader);
    program->addShader(fShader);
    program->link();

    vao = new QOpenGLVertexArrayObject;
    vao->create();
    vao->bind();
    program->bind();
    vbo = new QOpenGLBuffer;
    vbo->create();
    vbo->bind();
    static const float vertices[] = {
            -0.5f, -0.5f, 1.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f,-1.0f};
    vbo->allocate(vertices, 9 * sizeof(float));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    vbo->release();

}

void OpenGLWidget::resieGL(int w, int h)
{
    glViewport(0, 0, w, h);


}

void OpenGLWidget::paintGL()
{
    glClearColor(0.6f, 0.8f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    program->bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
