#include <ncurses.h>
#include "Window.hpp"

using namespace std;

Window::Window()
{
  WINDOW *w = initscr();
  getmaxyx(w, terY, terX);
  windowX = terX;
  windowY = terY;
}

double Window::terX;
double Window::terY;
