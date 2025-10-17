all:; gcc -Wall -Wextra -std=c11 main.c src/input.c src/board.c src/snake.c -lncurses -o run
clean:; rm -f run
