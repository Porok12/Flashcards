#include "pathmanager.h"

PathManager* PathManager::_instance = nullptr;

PathManager::PathManager()
{

}

PathManager *PathManager::getInstance()
{
    if(_instance == nullptr) {
        _instance = new PathManager();
    }

    return _instance;
}

std::string PathManager::getPath(Paths path)
{
    switch (path) {
        case FONT_PATH:
        return "/home/przemek/Projects/QtCreator/Flashcards/app/fonts/";
        case SHADERS_PATH:
        return "/home/przemek/Projects/QtCreator/Flashcards/app/shaders/";
    default:
        return "/home/przemek/Projects/QtCreator/Flashcards/app/";
    }
}
