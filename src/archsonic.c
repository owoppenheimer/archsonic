#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "../include/archsonic_types.h"

struct {
    unsigned int height, width;
} window_size;

void geterr(const char* error) {
    fprintf(stderr, "Ошибка: %s\n", error);
}

int main(void) {
    char* str_height = malloc(32 * sizeof(char));
    char* str_width = malloc(32 * sizeof(char));

    if (!str_height || !str_width) {
        geterr("Ошибка выделения памяти.");
        if (str_height) free(str_height);
        if (str_width) free(str_width);
        return 1;
    }

    strcpy(str_height, "Высота: ");
    strcpy(str_width, "Ширина: ");

    setlocale(LC_ALL, "");
    initscr();
    noecho();

    refresh();

    while (1) {
        getmaxyx(stdscr, window_size.height, window_size.width);
        term_point point = { window_size.height / 2, window_size.width / 2 };

        clear();

        sprintf(str_height + strlen("Высота: "), "%d", window_size.height);
        sprintf(str_width + strlen("Ширина: "), "%d", window_size.width);
        mvprintw(point.y - 1, point.x - strlen(str_width) / 2, "%s", str_width);
        mvprintw(point.y, point.x - strlen(str_height) / 2, "%s", str_height);
        int c = getch();
        if (c == 27) { break; refresh(); }  
    }

    free(str_height);
    free(str_width);
    endwin();
    return 0;
}
