/* Mock Implementation of ncurses for unit tests.
//
// Everything mocked to succeed
*/

#include <iostream>
#include <ncurses.h>

WINDOW *initscr() {
  std::cout << "Mock Ncurses initscr called" << std::endl;
  return OK;
}
int start_color() {
  std::cout << "Mock Ncurses start_color called" << std::endl;
  return OK;
}
int cbreak() {
  std::cout << "Mock Ncurses cbreak called" << std::endl;
  return OK;
}
int noecho() {
  std::cout << "Mock Ncurses noecho called" << std::endl;
  return OK;
}
int curs_set(int i) {
  std::cout << "Mock Ncurses curs_set called with (" << i << ")" << std::endl;
  return OK;
}
int keypad(WINDOW *win, bool bf) {
  std::cout << "Mock Ncurses keypad called with (" << win << ", " << bf << ")"
            << std::endl;
  return OK;
}
int nodelay(WINDOW *win, bool bf) {
  std::cout << "Mock Ncurses nodelay called with (" << win << ", " << bf << ")"
            << std::endl;
  return OK;
}
int endwin() {
  std::cout << "Mock Ncurses endwin called" << std::endl;
  return OK;
}

int init_pair(short id, short fg, short bg) {
  std::cout << "Mock Ncurses init_pair was called with (" << id << ", " << fg
            << ", " << bg << ")" << std::endl;
  return 0;
}

int clear() {
  std::cout << "Mock Ncurses clear called" << std::endl;
  return OK;
}

int refresh() {
  std::cout << "Mock Ncurses refresh called" << std::endl;
  return OK;
}
