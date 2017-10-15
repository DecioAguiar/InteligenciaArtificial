#include "tabledrivenagent.h"
#include <iostream>

using namespace std;

Action TableDrivenAgent::selectAction(Perception perception){

    Action action;

    pair <bool, bool> p;
    p = make_pair(perception.location, perception.isDirty);

    perceptions.push_back(perception);

    action.name = table[p];
    return action;

}

