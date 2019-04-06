#ifndef DECORATOR_H
#define DECORATOR_H

#include "visualcomponent.h"

class Decorator : public VisualComponent
{
public:
    Decorator(VisualComponent* component);

    virtual void draw();
private:
    VisualComponent* _component;
};

#endif // DECORATOR_H
