#include "openglwidget.h"

#include <QOpenGLShaderProgram>

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent), program(nullptr)
{

}

OpenGLWidget::~OpenGLWidget()
{    
    delete program;
    delete textRenderer;
    delete fbo;
    delete reverse;
    delete font;
    delete timer;
    delete mesh;
}

void OpenGLWidget::initializeGL()
{
    makeCurrent();
    initializeOpenGLFunctions();

    font = new ShaderProgram("font");
    font->setUniformValue("texture", 0);

    program = new ShaderProgram("flashcard");
    program->setUniformValue("tex", 0);

    reverse = new ShaderProgram("reverse");

    mesh = new FlashcardMesh();

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
    fbo = new QOpenGLFramebufferObject(800, 600);

    textRenderer = new TextRenderer();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,  SLOT(update()));
    timer->start(125);
}

void OpenGLWidget::resizeGL(int w, int h)
{
    float aspect = static_cast<float>(w) / h;
    projection.setToIdentity();
    projection.perspective(45.0f, aspect, 0.1f, 100.0f);
    ortho.setToIdentity();
    ortho.ortho(0.0f, w, 0.0f, h, 0.0f, 2.0f);
    textRenderer->ortho = ortho;
}

void OpenGLWidget::paintGL()
{
    //fbo
    fbo->bind();
    glClearColor(0.35f, 0.4f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    textRenderer->renderText("Hello!", 100, 100, 1.0f);
    fbo->release();
    //fbo
    //glViewport(0, 0, width(), height());

    glClearColor(0.6f, 0.8f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, fbo->takeTexture());

    program->bind();
    program->setUniformValue(program->uniformLocation("project_matrix"), projection);
    model.rotate(10.0f, QVector3D(0, 1, 0));
    program->setUniformValue(program->uniformLocation("mv_matrix"), view * model);

    mesh->draw();

    program->release();

    textRenderer->renderText("World!", 10, 10, 1.0f);
}

void OpenGLWidget::mousePressEvent(QMouseEvent *event)
{

}
