/* Mock Implementation of ncurses for unit tests.
//
// getch() is mocked to return an input
*/

#include <ncurses.h>

int wgetch(WINDOW *screen) {
  (void)screen;
  return 'a';
}

