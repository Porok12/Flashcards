#ifndef PATHMANAGER_H
#define PATHMANAGER_H

#include <string>

enum Paths {
    FONT_PATH,
    SHADERS_PATH,
    DEFAULT_PATH
};

class PathManager
{
private:
    PathManager();
    static PathManager* _instance;
public:
    static PathManager* getInstance();
    std::string getPath(Paths path);
};

#endif // PATHMANAGER_H
