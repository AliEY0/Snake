#ifndef SNAKE_H
#define SNAKE_H
#include "board.h"
#include <stdbool.h>

typedef struct{
    int row;
    int col;
} Point;


typedef struct{
    Point body[ROW*COLUMN];
    int dir; //0 is rechts; 1 is beneden; 2 is links; 3 is boven; 

} Snake;

void init_snake(Snake *snake);
void draw_snake(Board *board, Snake *snake);
void add_tail(Snake *snake);


void update_pos(Snake *snake, int row, int col);
void move_left(Board *board, Snake *snake, int row, int col);
void move_right(Board *board, Snake *snake, int row, int col);
void move_block(Board *board, Snake *snake);
void top_collision(Board *board, Snake *snake, int row, int col);
void bottom_collision(Board *board, Snake *snake, int row, int col);

int len_snake(Snake *snake);

void play_simulate(Board *board, Snake *snake);

#endif
