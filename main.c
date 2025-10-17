#include <stdio.h>
#include "src/board.h"
#include "src/input.h"
#include <ncurses.h>
#include "src/snake.h"
#include <unistd.h>


int main() {
    initscr();
    keypad(stdscr, TRUE);  
    nodelay(stdscr, TRUE); 
    noecho();              
    curs_set(0);               
    
    Snake snake;
    init_snake(&snake);
    snake.dir = 0;
    
    Board board;
    init_board(&board);
    
    draw_snake(&board,&snake);
    draw_board(&board);
    
    sleep(1);
    //move_block(&board, &snake);
    move_left(&board, &snake, snake.body[0].row, snake.body[0].col);
    
    draw_snake(&board,&snake);
    draw_board(&board);
        
    int ch;
    while ((ch = getch()) != 'q') {
        

    }

    endwin();
    return 0;
}


