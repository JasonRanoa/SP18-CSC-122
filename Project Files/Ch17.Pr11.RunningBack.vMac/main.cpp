#include <iostream>
#include <ncurses.h>

int main() {
	initscr();
	std::cout << "Hello, World!" << std::endl;
	endwin();
}
