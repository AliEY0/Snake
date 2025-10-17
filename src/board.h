#ifndef BOARD_H

#define BOARD_H
#define ROW 10
#define COLUMN 10

#include <stdbool.h>
//#include "snake.h"



typedef struct{
    char arr[ROW][COLUMN];
    
} Board;


void init_board(Board *board);
void draw_board(Board *board);
void clear_board(Board *board);

#endif
