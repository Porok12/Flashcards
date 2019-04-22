#include "renderer.h"

//template<class T>
//T* Renderer<T>::_instance = nullptr;

//template<class T>
Renderer::~Renderer()
{
    delete vao;
    delete vbo;
    delete program;
}

//template<class T>
void Renderer::render2(BasicWidget *widget)
{

}

/*template<class T>
T *Renderer<T>::getInstance()
{
    if(_instance == nullptr) {
        _instance = new T();
    }

    return _instance;
}*/
