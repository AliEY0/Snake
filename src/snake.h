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
void spawn_apple(Board *board, Snake *snake);
void init_snake(Snake *snake);
void draw_snake(Board *board, Snake *snake);
void add_tail(Board *board, Snake *snake, int row, int col);


void update_pos(Board *board, Snake *snake, int row, int col);

void move_up(Board *board, Snake *snake, int row, int col);
void move_down(Board *board, Snake *snake, int row, int col);

void move_left(Board *board, Snake *snake, int row, int col);

void move_right(Board *board, Snake *snake, int row, int col);
void move_block(Board *board, Snake *snake);

bool collision(Board *board, int row, int col);
int len_snake(Snake *snake);

void play_simulate(Board *board, Snake *snake);

#endif
