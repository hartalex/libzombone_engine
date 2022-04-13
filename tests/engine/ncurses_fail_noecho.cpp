/* Mock Implementation of ncurses for unit tests.
//
// noecho() is mocked to fail
*/

#include <ncurses.h>

#include <iostream>
using namespace std;

WINDOW *initscr() {
  cout << "Mock Ncurses initscr called" << endl;
  return OK;
}
int start_color() {
  cout << "Mock Ncurses start_color called" << endl;
  return OK;
}
int cbreak() {
  cout << "Mock Ncurses cbreak called" << endl;
  return OK;
}
int noecho() {
  cout << "Mock Ncurses noecho called" << endl;
  return ERR;
}
int curs_set(int i) {
  cout << "Mock Ncurses curs_set called with (" << i << ")" << endl;
  return OK;
}
int keypad(WINDOW *win, bool bf) {
  cout << "Mock Ncurses keypad called with (" << win << ", " << bf << ")"
       << endl;
  return OK;
}
int nodelay(WINDOW *win, bool bf) {
  cout << "Mock Ncurses nodelay called with (" << win << ", " << bf << ")"
       << endl;
  return OK;
}
int endwin() {
  cout << "Mock Ncurses endwin called" << endl;
  return OK;
}
