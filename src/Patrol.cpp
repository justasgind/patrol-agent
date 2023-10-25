#include <iostream>
#include <random>

#include "../include/Patrol.h"

Patrol::Patrol(int startX, int startY) {
 x = startX;
 y = startY;

 state = onDuty;
}

void Patrol::Move() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(-2, 2);

    int patrolX = dis(gen);
    int patrolY = dis(gen);

    Player::Move(patrolX, patrolY);
}

void Patrol::PerformDuty() {
    state = onDuty;
}

void Patrol::OpenFire() {
    state = onFire;
}
