#include "flashcardmanager.h"

FlashcardManager::FlashcardManager() : model()
{
    timer = std::unique_ptr<QTimer>(new QTimer(this));
    counter = 0;
    Flashcard fc = Flashcard();
    fc.word = "Kot";
    fc.translation = "Cat";
    fcards.push_back(fc);
}

Flashcard FlashcardManager::getCard()
{
    return fcards.front();
}

void FlashcardManager::paint(std::shared_ptr<ShaderProgram> program,
                             std::shared_ptr<QTimer> timer)
{
    model.Draw(getCard(), program, timer);
}

void FlashcardManager::set(std::vector<Flashcard> fcards)
{
    this->fcards = fcards;
}

void FlashcardManager::getNext()
{

}

void FlashcardManager::init(const QObject* receiver)
{
    connect(timer.get(), SIGNAL(timeout()), receiver, SLOT(update()));
    timer->start(1);
}

void FlashcardManager::next()
{

}

void FlashcardManager::flip()
{
    model.rotate(45);
}
