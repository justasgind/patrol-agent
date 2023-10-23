#include "../include/Agent.h"

Agent::Agent(int startX, int startY) : y(startX), x(startY) {

}

void Agent::Move(int dx, int dy) {
    int newX = x + dx;
    int newY = y + dy;

    if (newX >= 0 && newX <= maxRangeX && newY >= 0 && newY <= maxRangeY) {
        x = newX;
        y = newY;
    }
}

int Agent::getX() const {
    return x;
}

int Agent::getY() const {
    return y;
}
