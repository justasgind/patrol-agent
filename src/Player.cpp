#include "../include/Player.h"

void Player::Move(int dx, int dy) {
    int newX = x + dx;
    int newY = y + dy;

    if (newX >= 0 && newX <= maxRangeX && newY >= 0 && newY <= maxRangeY) {
        x = newX;
        y = newY;
    }
}

int Player::getX() const {
    return x;
}

int Player::getY() const {
    return y;
}
