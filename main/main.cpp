#include <random>
#include <ncurses.h>
#include "MyCursor.hpp" 
#include "Frame.hpp"
using namespace std;

double terx, tery;

int main()
{
  WINDOW *w = initscr();

  getmaxyx(w, tery, terx);

  noecho();
  cbreak();

  curs_set(1);

  Frame fr(terx, tery);

  MyCursor obj(1, 1);

  move(1, 1);

  while (true)
  {
    obj.mycursor(getch());

    refresh();
  }

  endwin();
}
