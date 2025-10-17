#include <stdio.h>
#include "board.h"
#include "snake.h"
#include "input.h"
#include <unistd.h>

void update_pos(Snake *snake, int row, int col){
    for(int i = len_snake(snake) - 1; i >=1 ; i--){
        snake->body[i].row = snake->body[i-1].row;
        snake->body[i].col = snake->body[i-1].col;
   }

    snake->body[0].row = row;
    snake->body[0].col = col;

}

int len_snake(Snake *snake){
    
    for(int i = 0; i < COLUMN * ROW; i++){
        if(snake->body[i].row == -1)
            return i;
    }
    return ROW * COLUMN;
}
void init_snake(Snake *snake){
        
    for(int i = 0; i < COLUMN * ROW; i++){
        snake->body[i].row = -1;
        snake->body[i].col = -1;
    }

    int n = 3;
    for(int i = 0; i < n; i++){
        snake->body[i].row = ROW/2;
        snake->body[i].col = COLUMN/2-i;
    }

    

}


//0 is rechts; 1 is beneden; 2 is links; 3 is boven;
void move_right(Board *board, Snake *snake, int row, int col){
    switch (snake->dir) {
        case 0:
            update_pos(snake, row + 1, col);                  
            snake->dir = 3;
            break;
        case 1:
            update_pos(snake, row , col+1);                  
            snake->dir = 0;
            break;
        case 2:
            update_pos(snake, row - 1, col);                  
            snake->dir = 1;
            break;
        case 3:
            update_pos(snake, row , col - 1);                  
            snake->dir = 2;
            break;
    }
}

void move_left(Board *board, Snake *snake, int row, int col){
    init_board(board);
    switch (snake->dir) {
        case 0:
            update_pos(snake, row + 1, col);                  
            snake->dir = 3;
            break;
        case 1:
            update_pos(snake, row , col+1);                  
            snake->dir = 0;
            break;
        case 2:
            update_pos(snake, row - 1, col);                  
            snake->dir = 1;
            break;
        case 3:
            update_pos(snake, row , col - 1);                  
            snake->dir = 2;
            break;
    }
}


void draw_snake(Board *board, Snake *snake){
    
    for(int i = 0; i < len_snake(snake); i++){
        if(i == 0)
        board->arr[snake->body[i].row][snake->body[i].col] = 'X';
        else
        board->arr[snake->body[i].row][snake->body[i].col] = '*';
    }

}

void move_block(Board *board, Snake *snake){
    
    init_board(board);
    int rs = snake->body[0].row;
    int cs = snake->body[0].col;

    switch (snake->dir) {
        case 0:
            update_pos(snake, rs, cs + 1);
            break;
        case 1:
            update_pos(snake, rs - 1, cs);
            break;
        case 2:
            update_pos(snake, rs, cs - 1);
            break;
        case 3:
            update_pos(snake, rs+1, cs);
            break;

    }
    
    draw_snake(board, snake);

}

void add_tail(Snake *snake){
    
}



void play_simulate(Board *board, Snake *snake){


    
    while(1){
        int val = read_input();
        //0 is rechts; 1 is beneden; 2 is links; 3 is boven;
        switch (val) {
            case 2:
                

                break;
        }


    }






}
