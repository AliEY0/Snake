#ifndef BOARD_H

#define BOARD_H
#define ROW 50
#define COLUMN 50

#include <stdbool.h>
//#include "snake.h"



typedef struct{
    char arr[ROW][COLUMN];
    int apple_row;
    int apple_col;
} Board;


void init_board(Board *board);
void draw_board(Board *board);
//void clear_board(Board *board);
//void spawn_apple(Board *board);

#endif
