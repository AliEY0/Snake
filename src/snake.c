#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include "board.h"
#include "snake.h"
#include "input.h"
#include <unistd.h>


bool collision(Board *board, int row, int col){
    if(row < 0 || row >= ROW){
        return true;
    }
    if(col < 0 || col >= COLUMN){
        return true;
    }
    if(board->arr[row][col] == '*') return true;
    return false;

}


void update_pos(Board *board, Snake *snake, int row, int col){
    
    if(collision(board, row,  col) == true) return;

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

    int n = 5;
    for(int i = 0; i < n; i++){
        snake->body[i].row = ROW/2;
        snake->body[i].col = COLUMN/2-i;
    }

    

}


//0 is rechts; 1 is beneden; 2 is links; 3 is boven;
void move_right(Board *board, Snake *snake, int row, int col){
    if(snake->dir % 2 == 1){
        update_pos(board, snake, row , col+1);
        snake->dir = 0;
    }
}

void move_left(Board *board, Snake *snake, int row, int col){
    //init_board(board);
    
    if(snake->dir % 2 == 1){
        update_pos(board, snake, row , col-1);
        snake->dir = 2;
    }

}
void move_up(Board *board, Snake *snake, int row, int col){
    if(snake->dir % 2 == 0){
        update_pos(board, snake, row + 1, col);
        snake->dir = 3;
    }
}
void move_down(Board *board, Snake *snake, int row, int col){
    if(snake->dir % 2 == 0){
        update_pos(board,snake, row - 1, col);
        snake->dir = 1;
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
    
    //init_board(board);
    int rs = snake->body[0].row;
    int cs = snake->body[0].col;

    switch (snake->dir) {
        case 0:
            update_pos(board, snake, rs, cs + 1);
            break;
        case 1:
            update_pos(board, snake, rs - 1, cs);
            break;
        case 2:
            update_pos(board, snake, rs, cs - 1);
            break;
        case 3:
            update_pos(board, snake, rs+1, cs);
            break;

    }
    
    draw_snake(board, snake);

}

void add_tail(Board *board,Snake *snake, int row, int col){
    //init_board(board);
    for(int i = len_snake(snake); i >= 1; i--){
        snake->body[i].col = snake->body[i - 1].col; 
        snake->body[i].row = snake->body[i - 1].row; 
    }
    board->arr[board->apple_row][board->apple_col] = 'X';
    snake->body[0].col = col;
    snake->body[0].row = row;
}


/* switch (ch) {
 13         case 'q':
 14         case 'Q':
 15         case KEY_UP:
 16             return 2;  //L
 17         case 'd':
 18         case 'D':
 19         case KEY_LEFT:
 20             return 3;  //R
 21         case 's':
 22         case 'S':
 23         case KEY_DOWN:
 24             return 4;  //DOWN
 25         case 'w':
 26         case 'W':
 27         case KEY_RIGHT:
 28             return 5;  //R
 29         case 'p':
 30         case 'P':
 31             return -1; //Q
 32         default:
 33             return 0;  //
 34     }*/
void spawn_apple(Board *board, Snake *snake){
      
    int rs =-1;
    int cs =-1;

    board->apple_row = rs;
    board->apple_col = cs;
    
    bool found = false;
    do{
        rs = rand() % ROW;
        cs = rand() % COLUMN;
        for(int i = 0; i < len_snake(snake); i++){
            if(snake->body[i].row == rs && snake->body[i].col == cs){
                found = true;
                break;
            }
        }

    } while(found == true);





     board->apple_row = rs;
     board->apple_col = cs;
}
bool eat_apple(Board *board, Snake *snake){
    if((snake->body[0].row == board->apple_row )&& (snake->body[0].col) == board->apple_col){
                return true;
    }
    return false;
}


void play_simulate(Board *board, Snake *snake){
    //srand(time(NULL));

    int delay = 100000; 
    int pending_input = 0; 
    while(1){
        int xPos = -1;
        int yPos = -1;
        int rs = snake->body[0].row;
        int cs = snake->body[0].col;
        int val = read_input();
        //0 is rechts; 1 is beneden; 2 is links; 3 is boven;
        if(collision(board, rs, cs) == true){
            return;
        }
        switch (val) {

            case 2:
                move_up(board, snake, rs, cs);
                break;
            case 3:
                move_left(board, snake, rs, cs);
                break;
            case 4:
                move_down(board, snake, rs, cs);
                break;
            case 5:
                move_right(board, snake, rs, cs);
                break;
            case -1:
                return;
                break;
        }
        init_board(board);
        board->arr[board->apple_row][board->apple_col] = 'O';
        move_block(board, snake);
        draw_snake(board, snake);
        if(eat_apple(board, snake) == true){
            add_tail(board, snake, board->apple_row, board->apple_col);
            spawn_apple(board, snake); 
           // draw_snake(board, snake);
            
        }
        draw_board(board);
        usleep(delay);
    }







}
