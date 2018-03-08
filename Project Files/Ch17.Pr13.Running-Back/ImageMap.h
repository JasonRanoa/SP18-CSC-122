#include <iostream>
#include <list>
#include <ncurses.h>
#include <curses.h>
using namespace std;

// const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

struct COORD {
    int X;
    int Y;
    COORD() {
        X = 0;
        Y = 0;
    }
    COORD(int dx, int dy) {
        X = dx;
        Y = dy;
    }
};

class ImageMap:list<COORD>{

public:
    // Add an array of coordinates to the image map
    void add(COORD coordArray[]);
    // Convenience method for adding an array of coordinates
    void add(short *coordAsShorts);
    // Display a given character at a specified position
    void displayAt(char ch, int col, int row);
    // Display an asterisk at a given position
    void displayAt(int col, int row)
    {
        displayAt('*', col, row);
    }
    // Erase whatever character is at a given position
    void eraseAt(int col, int row)
    {
        displayAt(' ', col, row);
    }
};
