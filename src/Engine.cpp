#include <ncurses.h>
#include <iostream>

#include "../include/Engine.h"

int Engine::run() {
        initscr();
        cbreak();
        keypad(stdscr, TRUE);
        noecho();

        int c;

        while(1) {
            c = getch();

            switch(c) {
                case KEY_UP:
                    agent.Move(0, 1);

                    break;
                case KEY_DOWN:
                    agent.Move(0, -1);

                    break;
                case KEY_LEFT:
                    agent.Move(-1, 0);

                    break;
                case KEY_RIGHT:
                    agent.Move(1, 0);

                    break;
                default:
                    std::cout << "\r" << "This is not ARROW KEY!" << std::endl;
                    break;
            }
            action();

            display();
        }
};

int Engine::display() {
    system("clear");

    const char* GREEN = "\033[32m"; // Green
    const char* GREY = "\033[90m"; // Grey
    const char* RED = "\033[31m"; // Red
    const char* RESET = "\033[0m"; // Reset to default text color

    for (int y = maxRangeY; y >= 0; y--) {
        for (int x = 0; x <= maxRangeX; x++) {

            if (agent.getX() == x && agent.getY() == y) {
                std::cout << GREEN << "● " << RESET;

            } else if (patrol.getX() == x && patrol.getY() == y) {
                std::cout << RED << "● " << RESET;
            } else {
                std::cout << GREY << "0 " << RESET;
            }
        }
        std::cout << "\r" << std::endl;
    }

    std::cout << "\r" << GREEN << "Your " << RESET <<  "Coordinates: (" << agent.getX() << ", " << agent.getY() << ")\n";
    std::cout << "\r" << RED << "Patrol " << RESET <<  "Coordinates: (" << patrol.getX() << ", " << patrol.getY() << ")\n";
    std::cout << "\r" << std::endl;
    if (patrol.state == onDuty) {
        std::cout << "\r" << "Patrol is " << GREEN << "on duty" << RESET << std::endl;
    } else {
        std::cout << "\007";
        std::cout << "\r" << "Patrol is " << RED << "shooting " << RESET << "at you" << std::endl;
    }
}

void Engine::action() {
    double distance = sqrt(pow((patrol.getX() - agent.getX()), 2) + pow((patrol.getY() - agent.getY()), 2));

    if (distance < 10) {
        patrol.OpenFire();
    } else {
        patrol.PerformDuty();
        patrol.Move();
    }
};