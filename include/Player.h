#ifndef PATROL_AGENT_PLAYER_H
#define PATROL_AGENT_PLAYER_H

const int maxRangeX = 20;
const int maxRangeY = 20;

class Player {
public:
    int x, y;

    void Move(int dx, int dy);

    int getX() const;

    int getY() const;
};


#endif //PATROL_AGENT_PLAYER_H
