#include <ncurses.h>
#include "Window.hpp"

using namespace std;

Window::Window()
{
  WINDOW *w = initscr();
  noecho();
  cbreak();
  curs_set(1);
  idlok(w, true);
  keypad(stdscr, TRUE);

  getmaxyx(w, terY, terX);
  windowX = terX;
  windowY = terY;
}

double Window::terX;
double Window::terY;
