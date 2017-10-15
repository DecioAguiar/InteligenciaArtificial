#include "enviroment.h"

Enviroment::Enviroment()
{

}

Perception Enviroment::updateEnviroment(Action acao){
    Perception p;
    if(acao.name == "Aspirar"){
        if(agentLocation){
            isDirtyB = 0;
            p.isDirty = 0;
            p.location = 1;
        } else {
            isDirtyA = 0;
            p.isDirty = 0;
            p.location = agentLocation;
        }
    } else if(acao.name == "Direita"){
        agentLocation = 1;

        p.location = agentLocation;
        p.isDirty = isDirtyB;
    } else {
        agentLocation = 0;

        p.location = agentLocation;
        p.isDirty = isDirtyA;
    }
    return p;
}

