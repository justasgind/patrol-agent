#ifndef PATROL_AGENT_AGENT_H
#define PATROL_AGENT_AGENT_H

const int maxRangeX = 20;
const int maxRangeY = 20;

class Agent {
    int x, y;

public:
    Agent(int startX, int startY);

    void Move(int dx, int dy);

    int getX() const;

    int getY() const;
};


#endif //PATROL_AGENT_AGENT_H
