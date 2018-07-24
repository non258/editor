#include <ncurses.h>
#include "MyCursor.hpp"
#include "Frame.hpp"
#include "Window.hpp"


MyCursor::MyCursor(double x, double y) : myX(x), myY(y)
{
  
}

void MyCursor::redraw()
{
  move(myY, myX);
}

void MyCursor::curmove(int udlr)
{
  switch(udlr)
  {
    case UP:     myY--;      break;
    case DOWN:   myY++;      break;
    case LEFT:   myX--;      break;
    case RIGHT:  myX++;      break;
  }

  move(myY, myX);
}


void MyCursor::mycursor(char num_move)
{
  if (num_move == 4)
    this -> curmove(LEFT);
  else if (num_move == 2)
    this -> curmove(DOWN);
  else if (num_move == 3)
    this -> curmove(UP);
  else if (num_move == 5)
    this -> curmove(RIGHT);
}

void MyCursor::inputText(char chtxt)
{
  insch(chtxt);
  curmove(RIGHT);
}

void MyCursor::enter(char enter)
{
  myX = 0;
  curmove(DOWN);
}

bool MyCursor::isMove(char c)
{
  if (c == 2 || c == 3 || c == 4 || c == 5)
    return true;
  return false;
}
