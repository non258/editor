#include <ncurses.h>
using namespace std;
#include "Frame.hpp"

Frame::Frame(double x, double y) : frameX(x), frameY(y)
{

}

void Frame::popFrame(Window w)
{
  window = w;
  double x = frameX;
  double y = frameY;

  move(0, 0);

  for (int i = 0; i < y - 1; i++)
  {
    for (int j = 0; j < x; j++)
    {
      // 左上
      if (i == 0 && j == 0)
        printw(" ");

      // 右上
      else if (i == 0 && j == x - 1)
        printw(" ");

      // 左下
      else if (i == y - 2&& j == 0)
        printw(" ");

      // 右下
      else if (i == y - 2 && j == x - 1)
        printw(" ");

      // 上下 
      else if (i == 0 || i == y - 2)
        printw("-");

      // 左右 
      else if (j == 0 || j == x - 1)
        printw("|");

      else
        printw(" ");

      if (j == x)
        printw("\n");
    }
  }
}

bool Frame::checkCursor(double x, double y)
{
  if (frameX - 1 <= x || x <= window.windowX - frameX)
    return true;
  if (frameY - 2 <= y || y <= window.windowY - frameY)
    return true;
  return false;
}
