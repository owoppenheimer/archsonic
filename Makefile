all: test

test: ui.c
	clang -Wall -Wextra -g -lncurses ui.c -o test
