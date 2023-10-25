#ifndef PATROL_AGENT_ENGINE_H
#define PATROL_AGENT_ENGINE_H

#include "Agent.h"
#include "Patrol.h"

class Engine {
    Agent agent = Agent(0, 0);
    Patrol patrol = Patrol(10, 10);

public:
    int run();

    int display();

    void action();
};


#endif //PATROL_AGENT_ENGINE_H
