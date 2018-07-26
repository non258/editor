#include <ncurses.h>
#include "MyCursor.hpp"
#include "Window.hpp"
#include "Editor.hpp"


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


void MyCursor::mycursor(char num_move, Editor &edi)
{
  if (num_move == 4)
    this -> curmove(LEFT, edi);
  else if (num_move == 2)
    this -> curmove(DOWN, edi);
  else if (num_move == 3)
    this -> curmove(UP, edi);
  else if (num_move == 5)
    this -> curmove(RIGHT, edi);
}

void MyCursor::curmove(int udlr, Editor &edi)
{
  switch(udlr)
  {
    case UP:
      if (myY >= 0)
      {
        if (myY == 0 && edi.viewY > 0)
          edi.viewY--;
        else if (myY > 0)
          myX = min((int)myX, edi.getWidth(--myY));
      }
      break;
    case DOWN:
      if (myY < edi.getHeight() - 1)
      {
        if (myY == Window::terY - 1 /* && linesの一番最後の要素の位置にいなかったら */)
          edi.viewY++;
        else if (myY > Window::terY)
          myX = min((int)myX, edi.getWidth(++myY));
      }
      break;
    case LEFT:
      if (myX > 0)
        myX--;
      break;
    case RIGHT:
      if (myX < edi.getWidth(myY))
        myX++;
      break;
  }

  move(myY, myX);
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
