#include <random>
#include <ncurses.h>
#include "MyCursor.hpp" 
using namespace std;

int terx, tery;

int main()
{
  WINDOW *w = initscr();

  getmaxyx(w, tery, terx);

  noecho();
  cbreak();

  curs_set(1);

  MyCursor obj(0, 0);

  move(0, 0);

  while (true)
  {
    obj.mycursor(getch());

    refresh();
  }

  endwin();
}
