#include "../include/archsonic_types.h"
#include "../include/archsonic_arch.h"
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

WINDOW* win = NULL;
static char* text = NULL;

/* Reallocate memory for new text */
void realloc_text(const char* new_text) {
  char* tmp = realloc(text, strlen(new_text) + 1);
  if (!tmp) {
      geterror(1, "Failed to reallocate memory for text");
      return;
  }
  text = tmp;
  strcpy(text, new_text);
}

void init_window(void) {
   initscr();
   noecho();
   win = stdscr; // idk for what i did it

   /* Colors */
   start_color();
   init_pair(1, COLOR_WHITE, COLOR_BLACK);
   wbkgd(win, COLOR_PAIR(1));
}

/* Find termnal coordinates */
void find_coords(term_point *point, term_point *center) {
   getmaxyx(win, point->y, point->x);
   center->y = point->y / 2;
   center->x = point->x / 2;
}

/* Main function (now it's just a test) */
int main(void) {
   init_window();

   static term_point window_point;
   static term_point window_center;
   text = malloc(50 * sizeof(char)); // 50 bytes of memory for start (im rich)
   find_coords(&window_point, &window_center);

   strcpy(text, "Hello");
   mvprintw(window_center.y, window_center.x - strlen(text) / 2,
      "%s", text
   );
   getch();
   clear();
   refresh();

   realloc_text("Bye");
   mvprintw(window_center.y, window_center.x - strlen(text) / 2,
      "%s", text
   );

   getch();
   endwin();
   free(text);
   return 0;
}

/* TODO: learn ncurses */