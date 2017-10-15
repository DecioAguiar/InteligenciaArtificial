#include "simplereflexagent.h"




Action SimpleReflexAgent::selectAction(Perception perception){
    string acao;
    if(perception.isDirty){
        acao = "Aspirar";
    } else if(perception.location == 0){
        acao = "Direita";
    } else {
        acao = "Esquerda";
    }

    Action action;
    action.name = acao;
    return action;
}
