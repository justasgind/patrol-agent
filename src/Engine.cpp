#include <ncurses.h>
#include <iostream>

#include "../include/Engine.h"

int Engine::playerMovement() {
        initscr();
        cbreak();
        keypad(stdscr, TRUE);
        noecho();

        int c;

        while(1) {
            c = getch();

            int newX = agent.getX();
            int newY = agent.getY();

            switch(c) {
                case KEY_UP:
                    agent.Move(0, 1);
                    gameDisplay();

                    std::cout << "\r" << "Your Coordinates: (" << newX << ", " << newY << ")\n";
                    break;
                case KEY_DOWN:
                    agent.Move(0, -1);
                    gameDisplay();

                    std::cout << "\r" << "Your Coordinates: (" << newX << ", " << newY << ")\n";
                    break;
                case KEY_LEFT:
                    agent.Move(-1, 0);
                    gameDisplay();

                    std::cout << "\r" << "Your Coordinates: (" << newX << ", " << newY << ")\n";
                    break;
                case KEY_RIGHT:
                    agent.Move(1, 0);
                    gameDisplay();

                    std::cout << "\r" << "Your Coordinates: (" << newX << ", " << newY << ")\n";
                    break;
                default:
                    std::cout << "\r" << "This is not ARROW KEY!" << std::endl;
                    break;
            }
        }
};

int Engine::gameDisplay() {
    system("clear");

    const char* GREEN = "\033[32m"; // Green
    const char* RESET = "\033[0m"; // Reset to default text color

    for (int y = maxRangeY; y >= 0; y--) {
        for (int x = 0; x <= maxRangeX; x++) {

            if (agent.getX() == x && agent.getY() == y) {
                std::cout << GREEN << "2 " << RESET;
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << "\r" << std::endl;
    }
};
