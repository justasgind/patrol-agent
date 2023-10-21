#include <iostream>
#include <ncurses.h>

enum AgentState{
    onFire,
    onDuty
};

int main() {
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();

    int c;

    while(1) {
        c = getch();

        switch(c) {
            case KEY_UP:
                std::cout << "\r" << "Up" << std::endl; // Key up
                break;
            case KEY_DOWN:
                std::cout << "\r" << "Down" << std::endl; // Key down
                break;
            case KEY_LEFT:
                std::cout << "\r" << "Left" << std::endl; // Key left
                break;
            case KEY_RIGHT:
                std::cout << "\r" << "Right" << std::endl; // Key right
                break;
            default:
                std::cout << "\r" << "null" << std::endl; // Not key
                break;
        }
    }
    endwin();
    return 0;
}
