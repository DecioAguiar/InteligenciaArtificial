#ifndef SIMPLEREFLEXAGENT_H
#define SIMPLEREFLEXAGENT_H
#include "agent.h"


class SimpleReflexAgent : Agent
{
public:
    Action selectAction(Perception perception);
};

#endif // SIMPLEREFLEXAGENT_H
