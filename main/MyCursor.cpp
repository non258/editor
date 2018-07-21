#include <random>
#include <ncurses.h>
#include "MyCursor.hpp"
#include "Frame.hpp"
#include "Window.hpp"


MyCursor::MyCursor(double x, double y, Frame &f) : myX(x), myY(y), frame(f)
{
  
}

bool MyCursor::checkTouchFrame(double x, double y)
{
  if (frame.checkCursor(x, y))
    return true;
  return false;
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

 if (checkTouchFrame(myX, myY))
 {
  switch(udlr)
  {
    case UP:     myY++;      break;
    case DOWN:   myY--;      break;
    case LEFT:   myX++;      break;
    case RIGHT:  myX--;      break;
  }
 }

  move(myY, myX);
}


void MyCursor::mycursor(char num_move)
{
  if (num_move == 'h')
    this -> curmove(LEFT);
  else if (num_move == 'j')
    this -> curmove(DOWN);
  else if (num_move == 'k')
    this -> curmove(UP);
  else if (num_move == 'l')
    this -> curmove(RIGHT);
}
