#include <stdio.h>
#include "src/board.h"
#include "src/input.h"
#include <ncurses.h>
#include "src/snake.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
    initscr();
    keypad(stdscr, TRUE);  
    nodelay(stdscr, TRUE); 
    noecho();              
    curs_set(0);               
srand(time(NULL));    
    Snake snake;
    init_snake(&snake);
    snake.dir = 0;
    
    Board board;
    init_board(&board);
    board.apple_col = 10;
    board.apple_row = 10;
    draw_snake(&board,&snake);
    draw_board(&board);
    
    sleep(1);
    //move_block(&board, &snake);
    //move_left(&board, &snake, snake.body[0].row, snake.body[0].col);
    
    //spawn_apple(&board);    
    //draw_snake(&board,&snake);
    //draw_board(&board);
    play_simulate(&board, &snake);


    int ch;
    while ((ch = getch()) != 'q') {
        

    }

    endwin();
    return 0;
}


