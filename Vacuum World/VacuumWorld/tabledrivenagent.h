#ifndef TABLEDRIVENAGENT_H
#define TABLEDRIVENAGENT_H

#include "agent.h"
#include <map>
#include <utility>
#include <vector>

using namespace std;

class TableDrivenAgent : Agent
{
public:    

    map< pair<bool,bool>, string> table;

    vector<Perception> perceptions;

    Action selectAction(Perception perception);

};

#endif // TABLEDRIVENAGENT_H
