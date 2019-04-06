#include "flashcardmanager.h"

FlashcardManager::FlashcardManager(std::shared_ptr<DatabaseManager> dbmanager) : model()
{
    this->dbmanager = dbmanager;
    flashcard = dbmanager->getFlashcard(fcID = 1);
    timer = std::unique_ptr<QTimer>(new QTimer(this));
    counter = 0;
}

Flashcard FlashcardManager::getCard()
{
    return fcards[1];
}

void FlashcardManager::paint(std::shared_ptr<ShaderProgram> program,
                             std::shared_ptr<QTimer> timer,
                             std::shared_ptr<TextRenderer> textRenderer)
{
    model.Draw(flashcard, program, timer, textRenderer); //fcards[2]
    /*if(counter++ >= 44) {
        counter = 0;
        this->timer->stop();
    }*/
}

void FlashcardManager::set(std::vector<Flashcard> fcards)
{
    this->fcards = fcards;
}

void FlashcardManager::getNext()
{
    flashcard = dbmanager->getFlashcard(++fcID % 3 + 1);
}

void FlashcardManager::init(const QObject* receiver)
{
    //connect(this, SIGNAL(next()), receiver, SLOT(func));
    //connect(this, "next()", receiver, "update()");
    connect(timer.get(), SIGNAL(timeout()), receiver, SLOT(update()));
    timer->start(1);
    //connect(this, SIGNAL(next()), receiver, SLOT(update()));
}

void FlashcardManager::next()
{
    flashcard = dbmanager->getFlashcard(fcID++%3+1);
    /*if(!timer->isActive()) {
        model.act = action::UPDATE;
        timer->start(1);
    }*/
}

void FlashcardManager::flip()
{
    model.rotate(45);
    //model.act = action::ROTATE;
    //timer->start(1);
}
