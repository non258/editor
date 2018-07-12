#include <ncurses.h>
using namespace std;
#include "Frame.hpp"

Frame::Frame(double x, double y) : frameX(x), frameY(y)
{
  move(0, 0);

  for (int i = 0; i < y - 1; i++)
  {
    for (int j = 0; j < x; j++)
    {
      if (i == 0 && j == 0)
        printw(" ");

      else if (i == 0 && j == x - 1)
        printw(" ");

      else if (i == y - 2&& j == 0)
        printw(" ");

      else if (i == y - 2 && j == x - 1)
        printw(" ");


      else if (i == 0 || i == y - 2)
        printw("-");

      else if (j == 0 || j == x - 1)
        printw("|");

      else
        printw(" ");

      if (j == x)
        printw("\n");
    }
  }

}

double Frame::getSizeX()
{
  return frameX;
}

double Frame::getSizeY()
{
  return frameY;
}
