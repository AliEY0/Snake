#include <stdio.h>
#include "board.h"
#include "input.h"
#include <ncurses.h>


int main() {
    initscr();
    keypad(stdscr, TRUE);  
    nodelay(stdscr, TRUE); 
    noecho();              
    curs_set(0);               
    
    Board board;
    init_board(&board);
    draw_board(&board);
    
    int ch;
    while ((ch = getch()) != 'q') {
    }

    endwin();
    return 0;
}


