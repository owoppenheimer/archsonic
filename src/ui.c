/* User Interface. Version - alpha 0.1 |
*                                          |
* owoppenheimer, 06/04/2025                |
* ------------------------------------     |
* <owoppenheimer.ads@gmail.com>            |
*/

#include <ncurses.h>
#include "../include/archsonic_types.h" /* Some useful types */

int main(int argc, char* argv[]) {
   initscr();
 
   term_point point = { 10, 10 };
   move(point.y, point.x);

   printw("Type something");
   refresh();
   while (1) {
      noecho();

      delch();
      short c = getch();
      if (c == 27) break;
      refresh();

      move(point.y, point.x);
   }

   endwin();
   return 0;
}
