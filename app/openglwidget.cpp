#include "openglwidget.h"

#include <QOpenGLShaderProgram>

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{

}

void OpenGLWidget::initializeGL()
{
    makeCurrent();
    initializeOpenGLFunctions();

    font = std::shared_ptr<ShaderProgram>(new ShaderProgram("font"));
    font->setUniformValue("texture", 0);

    program = std::shared_ptr<ShaderProgram>(new ShaderProgram("flashcard"));
    program->setUniformValue("tex", 0);
    program->setUniformValue("tex2", 1);

    projection.setToIdentity();
    projection.perspective(45.0f, static_cast<float>(this->width()) / this->height(), 0.1f, 100.0f);
    view.setToIdentity();
    view.translate(QVector3D(0.0f, 0.0f, -2.0f));
    model.setToIdentity();

    timer = std::shared_ptr<QTimer>(new QTimer(this));
    connect(timer.get(), SIGNAL(timeout()), this,  SLOT(update()));

    fcmanager = std::unique_ptr<FlashcardManager>(new FlashcardManager());

    fcmanager->init(this);

    _renderer = std::unique_ptr<ContextRenderer>(new ContextRenderer());
}

void OpenGLWidget::resizeGL(int w, int h)
{
    float aspect = static_cast<float>(w) / h;
    projection.setToIdentity();
    projection.perspective(45.0f, aspect, 0.1f, 100.0f);
    ortho.setToIdentity();
    ortho.ortho(0.0f, w, 0.0f, h, 0.0f, 2.0f);

    TextRenderer::getInstance()->ortho = ortho;
}

void OpenGLWidget::paintGL()
{
    fcmanager->paint(program, timer);

    _renderer->render((new Label("/ˈaI.sE.leIt/"))->setX(10)->setY(10));
}

void OpenGLWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::RightButton) {
        fcmanager->next();
    }

    if(event->button() == Qt::MouseButton::LeftButton) {
        fcmanager->flip();
    }
}
