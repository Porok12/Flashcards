#include "flashcardmodel.h"

FlashcardModel::FlashcardModel()
{
    mesh = std::unique_ptr<FlashcardMesh>(new FlashcardMesh());

    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::NoAttachment);
    format.setMipmap(false);
    format.setSamples(4);
    format.setTextureTarget(GL_TEXTURE_2D);
    format.setInternalTextureFormat(GL_RGB16F);
    fbo = std::unique_ptr<QOpenGLFramebufferObject>(new QOpenGLFramebufferObject(800, 500));

    projection.setToIdentity();
    projection.perspective(45.0f, static_cast<float>(800) / 600, 0.1f, 100.0f);
    view.setToIdentity();
    view.translate(QVector3D(0.0f, 0.0f, -1.6f));
    model.setToIdentity();
}

void FlashcardModel::Draw(Flashcard fc, std::shared_ptr<ShaderProgram> program, std::shared_ptr<QTimer> timer)
{
    //if
    fbo->bind();
    glClearColor(0.7f, 0.8f, 0.9f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    TextRenderer::getInstance()->renderText(fc.word.toStdString().c_str(), 100, 100, 1.0f);
    fbo->release();
    GLuint texture = fbo->takeTexture();

    fbo->bind();
    glClearColor(0.7f, 0.8f, 0.9f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    TextRenderer::getInstance()->renderText(fc.translation.toStdString().c_str(), 200, 100, 1.0f);
    fbo->release();
    GLuint texture2 = fbo->takeTexture();
    //fi

    glClearColor(0.2f, 0.3f, 0.35f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);

    program->bind();
    program->setUniformValue(program->uniformLocation("project_matrix"), projection);
    //if(act == action::ROTATE)
    if(counter-->0) {
        model.rotate(4.0f, QVector3D(0, 1, 0));
        float d = (counter / 44.0f) * 2.0f - 1.0f;
        view.translate(0, 0, -0.1f * sin(d));
    }

    program->setUniformValue(program->uniformLocation("mv_matrix"), view * model);

    mesh->draw();

    program->release();
}


FlashcardModel::~FlashcardModel()
{

}

void FlashcardModel::rotate(int deg)
{
    counter = deg;
}
