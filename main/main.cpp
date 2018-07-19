#include <random>
#include <ncurses.h>
#include "MyCursor.hpp" 
#include "Frame.hpp"
#include "Window.hpp"
using namespace std;

int main()
{

  Window win;
  Frame fr(win.windowX, win.windowY);

  noecho();
  cbreak();

  curs_set(1);

  fr.popFrame(win);

  MyCursor obj(1, 1, fr);

  move(1, 1);

  while (true)
  {
    obj.mycursor(getch());

    refresh();
  }

  endwin();
}
