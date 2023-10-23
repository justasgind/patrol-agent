#ifndef PATROL_AGENT_ENGINE_H
#define PATROL_AGENT_ENGINE_H

#include "Agent.h"

class Engine {
    Agent agent = Agent(0, 0);

public:
    int playerMovement();

    int gameDisplay();
};


#endif //PATROL_AGENT_ENGINE_H
