#include <random>
#include <ncurses.h>
#include <string>
#include <vector>
#include "MyCursor.hpp" 
#include "Frame.hpp"
#include "Window.hpp"
#include "Editor.hpp"
using namespace std;

int main()
{

  Window win;
  Editor edi;
  edi.newpage();

  MyCursor obj(0, 0);

  while (true)
  {
    char c = getch();
    if (obj.isMove(c))
      obj.mycursor(c);
    else if (edi.isEnter(c))
    {
      edi.newLine(obj);
      edi.viewText();
    }
    else
    {
      edi.addChar(c, obj);
      edi.viewText();
    }
    obj.redraw();

    refresh();
  }

  endwin();
}
