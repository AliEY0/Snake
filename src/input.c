#include <ncurses.h>

#include "input.h"

int read_input() {
    int ch = getch();
    
    if (ch == ERR) {
        return 0;
    }

    switch (ch) {
        case 'q': 
        case 'Q': 
        case KEY_UP:
            return 2;  //L
        case 'd': 
        case 'D': 
        case KEY_LEFT:
            return 3;  //R
        case 's':
        case 'S':
        case KEY_DOWN: 
            return 4;  //DOWN
        case 'w':
        case 'W':
        case KEY_RIGHT:   
            return 5;  //R
        case 'p': 
        case 'P':     
            return -1; //Q
        default:       
            return 0;  // 
    }

}
