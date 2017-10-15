#ifndef ENVIROMENT_H
#define ENVIROMENT_H
#include "action.h"
#include "perception.h"

class Enviroment
{
public:
    Enviroment();
    bool isDirtyA;
    bool isDirtyB;
    bool agentLocation;

    Perception updateEnviroment(Action acao);

};

#endif // ENVIROMENT_H
