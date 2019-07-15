#ifndef FLASHCARDMANAGER_H
#define FLASHCARDMANAGER_H

#include <vector>
#include "flashcard.h"
#include "flashcardmodel.h"
#include "../Renderer/textrenderer.h"
#include <memory>

class FlashcardManager : public QOpenGLWidget, protected QOpenGLFunctions
{
private:
    std::vector<Flashcard> fcards;
    FlashcardModel model;
    Flashcard flashcard;

    std::unique_ptr<QTimer> timer;

    int fcID;
    int counter;
public:
    FlashcardManager();
    Flashcard getCard();
    void paint(std::shared_ptr<ShaderProgram> program,
               std::shared_ptr<QTimer> timer);
    void set(std::vector<Flashcard> fcards);

    void getNext();
    void getPrev();

    void init(const QObject* receiver);
    void next();
    void flip();
};

#endif // FLASHCARDMANAGER_H
