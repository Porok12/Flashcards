#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QtWidgets>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QObject>
#include <QTimer>
#include <memory>
#include "shaderprogram.h"
#include "textrenderer.h"
#include "flashcardmanager.h"
#include "databasemanager.h"
#include "contextrenderer.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include "fontfactory.h"
#include "label.h"
#include "button.h"

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    OpenGLWidget(QWidget *parent = nullptr);
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent *event) override;
private:
    std::shared_ptr<DatabaseManager> dbmanager;
    std::unique_ptr<FlashcardManager> fcmanager;
    std::shared_ptr<ShaderProgram> font, program;
    std::shared_ptr<QTimer> timer;
    std::unique_ptr<ContextRenderer> _renderer;

    QMatrix4x4 projection, model, view, ortho;

};

#endif // OPENGLWIDGET_H
