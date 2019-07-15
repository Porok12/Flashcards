#include "databasemanager.h"

DatabaseManager::DatabaseManager(const QString path)
{
    loadDatabase(path);
}

void DatabaseManager::loadDatabase(const QString path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if(!db.open()) {
        qDebug() << db.lastError();
    } else {
        qDebug() << "Connected to " << path;
    }
}

void DatabaseManager::addFlashcard(Flashcard card)
{

}

Flashcard DatabaseManager::getFlashcard(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM fcName WHERE id = :id");
    query.bindValue(":id", id);
    if(!query.exec())
        qDebug() << query.lastError();

    int word = query.record().indexOf("word");
    int translation = query.record().indexOf("translation");

    query.first();

    Flashcard fc;
    fc.word = query.value(word).toString();
    fc.translation = query.value(translation).toString();
    return fc;
}

std::vector<Flashcard> DatabaseManager::getFlashcards(QString name)
{
    QSqlQuery query;
    if(!query.exec(QString("SELECT * FROM %1").arg(name)))
        qDebug() << query.lastError();

    int word = query.record().indexOf("word");
    int translation = query.record().indexOf("translation");

    std::vector<Flashcard> fc;
    while(query.next()) {
        Flashcard temp;
        temp.word = query.value(word).toString();
        temp.translation = query.value(translation).toString();
        fc.push_back(temp);
    }
    return fc;
}
