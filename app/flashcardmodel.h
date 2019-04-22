#ifndef FLASHCARDMODEL_H
#define FLASHCARDMODEL_H

#include "flashcard.h"
#include "flashcardmesh.h"
#include "textrenderer.h"

enum action{NONE, ROTATE, UPDATE};

class FlashcardModel
{
private:
    QMatrix4x4 projection, model, view;
    std::unique_ptr<QOpenGLFramebufferObject> fbo;
    //std::unique_ptr<TextRenderer> textRenderer;
    int counter = 0;
public:
    void Draw(Flashcard fc, std::shared_ptr<ShaderProgram> program,
              std::shared_ptr<QTimer> timer);
    std::unique_ptr<FlashcardMesh> mesh;
    FlashcardModel();
    ~FlashcardModel();

    void rotate(int deg);
    action act = NONE;
};

#endif // FLASHCARDMODEL_H
