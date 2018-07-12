#include <random>
#include <ncurses.h>
#include "MyCursor.hpp" 
#include "Frame.hpp"
#include "Window.hpp"
using namespace std;

double terx, tery;

int main()
{
  WINDOW *w = initscr();

  getmaxyx(w, tery, terx);
  Window win(terx, tery);
  Frame fr(win.windowX, win.windowY);

  noecho();
  cbreak();

  curs_set(1);

  fr.popFrame();

  MyCursor obj(1, 1);

  move(1, 1);

  while (true)
  {
    obj.mycursor(getch());

    refresh();
  }

  endwin();
}
