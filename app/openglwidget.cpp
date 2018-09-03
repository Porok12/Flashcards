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
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f};
    vbo->allocate(vertices, 9 * sizeof(float));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    vbo->release();


    projection.setToIdentity();
    projection.perspective(45.0f, static_cast<float>(this->width()) / this->height(), 0.1f, 100.0f);
    view.setToIdentity();
    view.translate(QVector3D(0.0f, 0.0f, -2.0f));
    model.setToIdentity();
    //model.rotate(45.0f, QVector3D(0.0f, 1.0f, 0.0f));
}

void OpenGLWidget::resizeGL(int w, int h)
{
    float aspect = static_cast<float>(w) / h;
    projection.setToIdentity();
    projection.perspective(45.0f, aspect, 0.1f, 100.0f);
}

void OpenGLWidget::paintGL()
{
    //glViewport(0, 0, this->width(), this->height());

    glClearColor(0.6f, 0.8f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    program->bind();
    program->setUniformValue(program->uniformLocation("project_matrix"), projection);
    program->setUniformValue(program->uniformLocation("mv_matrix"), view * model);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void OpenGLWidget::mousePressEvent(QMouseEvent *event)
{

}
