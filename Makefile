# Makefile for Archsonic

CC=clang # i use clang by default, but you can use GCC if you want.
CFLAGS = -O3 -I include/ # optimization! i recommend you to use your favorite optimization level. e.g: -02
BIN=bin/archsonic
OBJ=obj/archsonic.o obj/artix.o obj/arch.o

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $^ -o $@ -lncurses

obj/%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f obj/* bin/*
