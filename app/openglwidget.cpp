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
    delete font;
    delete fontVao;
    delete fontVbo;
}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    QOpenGLShader *vShader3 = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vShader3->compileSourceFile("/home/przemek/Projects/QtCreator/Flashcards/app/font.vert");
    QOpenGLShader *fShader3 = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fShader3->compileSourceFile("/home/przemek/Projects/QtCreator/Flashcards/app/font.frag");
    font = new QOpenGLShaderProgram;
    font->addShader(vShader3);
    font->addShader(fShader3);
    font->link();
    font->bind();
    font->setUniformValue("texture", 0);

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
    //program->bind();
    vbo = new QOpenGLBuffer;
    vbo->create();
    vbo->bind();
    static const float vertices[] = {
            -0.5f, -0.5f, 0.0f, 0.0f,  0.0f,
             0.5f, -0.5f, 0.0f, 1.0f,  0.0f,
             0.5f,  0.5f, 0.0f, 1.0f,  1.0f,
            -0.5f,  0.5f, 0.0f, 0.0f,  1.0f
    };
    vbo->allocate(vertices, 20 * sizeof(float));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float)));
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
    fbo = new QOpenGLFramebufferObject(800, 600);



    //


    FT_Library ft;
    if(FT_Init_FreeType(&ft)) {
      fprintf(stderr, "Could not init freetype library\n");
      //return 1;
    }

    //FT_Face face;
    if(FT_New_Face(ft, "/home/przemek/Projects/QtCreator/Flashcards/app/Ubuntu.ttf", 0, &face)) {
      fprintf(stderr, "Could not open font\n");
      //return 1;
    }

    FT_Set_Pixel_Sizes(face, 0, 96);

//    if(FT_Load_Char(face, 'o', FT_LOAD_RENDER)) {
//      fprintf(stderr, "Could not load character 'X'\n");
//      //return 1;
//    }

    font->bind();
    fontVao = new QOpenGLVertexArrayObject;
    fontVao->create();
    fontVao->bind();
    fontVbo = new QOpenGLBuffer;
    fontVbo->setUsagePattern(QOpenGLBuffer::DynamicDraw);
    fontVbo->create();
    fontVbo->bind();
    GLfloat box[] = {
        0.0f, 100.0f, 0.0f, 0.0f,
        100.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
        100.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 100.0f, 1.0f, 0.0f,
        100.0f, 100.0f, 1.0f, 1.0f
    };
    fontVbo->allocate(box, 4 * 6 * sizeof(float));
    //fontVbo->allocate(4 * 6 * sizeof(float));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);

    fontVbo->release();
    fontVao->release();
}

void OpenGLWidget::resizeGL(int w, int h)
{
    float aspect = static_cast<float>(w) / h;
    projection.setToIdentity();
    projection.perspective(45.0f, aspect, 0.1f, 100.0f);
    ortho.setToIdentity();
    ortho.ortho(0.0f, w, 0.0f, h, 0.0f, 2.0f);
}

void OpenGLWidget::paintGL()
{
    //fbo
    fbo->bind();
    //glViewport(0, 0, 800, 600);
    glClearColor(0.35f, 0.4f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    renderText("Hello!", 100, 100, 1.0f);
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

    vao->bind();
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    vao->release();
    program->release();

    renderText("World!", 10, 10, 1.0f);
}

void OpenGLWidget::mousePressEvent(QMouseEvent *event)
{

}

void OpenGLWidget::renderText(const char *text, float x, float y, int size)
{
    const char *ptr;
    FT_GlyphSlot g = face->glyph;

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    font->bind();
    font->setUniformValue(font->uniformLocation("projection"), ortho);
    fontVao->bind();
    glActiveTexture(GL_TEXTURE0);

    for(ptr = text; *ptr; ptr++)
    {
        if(FT_Load_Char(face, *ptr, FT_LOAD_RENDER))
            continue;

        //GLuint tex;
        //glGenTextures(1, &tex);
        //glBindTexture(GL_TEXTURE_2D, tex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, g->bitmap.width, g->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, g->bitmap.buffer);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        float x2 = x + g->bitmap_left * size;
        float y2 = y + (g->bitmap.rows - g->bitmap_top) * size;
        float w = g->bitmap.width * size;
        float h = g->bitmap.rows * size;

        GLfloat box[] = {
            x2,     y2 + h, 0.0f, 0.0f,
            x2,     y2    , 0.0f, 1.0f,
            x2 + w, y2    , 1.0f, 1.0f,
            x2,     y2 + h, 0.0f, 0.0f,
            x2 + w, y2    , 1.0f, 1.0f,
            x2 + w, y2 + h, 1.0f, 0.0f
        };

        fontVbo->bind();
        fontVbo->write(0, box, 4 * 6 * sizeof(float));
        glDrawArrays(GL_TRIANGLES, 0, 6);
        fontVbo->release();

        x += (g->advance.x / 64) * size;
        y += (g->advance.y / 64) * size;
    }
    fontVao->release();
    font->release();
}
