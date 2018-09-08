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
    delete fbo;
    delete reverse;
    delete painter;
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

    program->bind();
    program->setUniformValue("tex", 0);

    QOpenGLShader *vShader2 = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vShader2->compileSourceFile("/home/przemek/Projects/QtCreator/Flashcards/app/reverse.vert");
    QOpenGLShader *fShader2 = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fShader2->compileSourceFile("/home/przemek/Projects/QtCreator/Flashcards/app/reverse.frag");
    reverse = new QOpenGLShaderProgram;
    reverse->addShader(vShader2);
    reverse->addShader(fShader2);
    reverse->link();


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


    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::NoAttachment);
    format.setMipmap(false);
    format.setSamples(4);
    format.setTextureTarget(GL_TEXTURE_2D);
    format.setInternalTextureFormat(GL_RGB16F);
    fbo = new QOpenGLFramebufferObject(512, 512);
//    // obverse reverse


}

void OpenGLWidget::resizeGL(int w, int h)
{
    float aspect = static_cast<float>(w) / h;
    projection.setToIdentity();
    projection.perspective(45.0f, aspect, 0.1f, 100.0f);
}

void OpenGLWidget::paintGL()
{
    fbo->bind();
    glClearColor(0.3f, 0.4f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    //reverse->bind();
    fbo->release();


//    painter = new QPainter(this);
//    painter->beginNativePainting();


    glClearColor(0.6f, 0.8f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, fbo->takeTexture());

    program->bind();
    program->setUniformValue(program->uniformLocation("project_matrix"), projection);
    program->setUniformValue(program->uniformLocation("mv_matrix"), view * model);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    program->release();



//    painter->endNativePainting();
//    painter->setPen(Qt::black);
//    painter->setFont(QFont("Helvetica", 120));
//    painter->drawText(80, 120, "text");
//    painter->end();
}

void OpenGLWidget::mousePressEvent(QMouseEvent *event)
{

}
