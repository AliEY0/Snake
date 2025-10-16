all:; gcc -Wall -Wextra -std=c11 src/main.c src/input.c src/board.c -lncurses -o run
clean:; rm -f run
