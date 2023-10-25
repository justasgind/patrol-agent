#ifndef PATROL_AGENT_PATROL_H
#define PATROL_AGENT_PATROL_H

#include "Player.h"

enum PatrolState {
    onDuty,
    onFire
};

class Patrol : public Player {

public:
    PatrolState state;

    void PerformDuty();

    void OpenFire();

    Patrol(int startX, int startY);

    void Move();
};


#endif //PATROL_AGENT_PATROL_H
