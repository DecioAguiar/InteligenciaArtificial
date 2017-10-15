#ifndef AGENT_H
#define AGENT_H

#include "perception.h"
#include "action.h"
#include <vector>

class Agent
{
public:
    Agent();
    Perception perception;
    vector<Action> actions;
};

#endif // AGENT_H
