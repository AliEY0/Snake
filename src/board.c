#include <stdbool.h>
#include <stdio.h>
#include "board.h"
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>


void clear_board(Board *board){

    

}

void init_board(Board *board)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            board->arr[i][j] = '.';
        }
    }
}

void draw_board(Board *board)
{
    clear();

    for (int i = ROW - 1; i >= 0; i--)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            mvaddch(ROW - 1 - i, j, board->arr[i][j]);
        }
    }

    refresh();
}

