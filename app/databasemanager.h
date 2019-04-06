#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql>
#include "flashcard.h"
#include <vector>

class DatabaseManager
{
private:
    QSqlDatabase db;
public:
    DatabaseManager(const QString path);

    void loadDatabase(const QString path);
    void addFlashcard(Flashcard card);
    Flashcard getFlashcard(int id);
    std::vector<Flashcard> getFlashcards(QString name);
};

#endif // DATABASEMANAGER_H
