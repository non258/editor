#include <random>
#include <ncurses.h>
#include "MyCursor.hpp"
#include "Frame.hpp"
#include "Window.hpp"
using namespace std;

MyCursor::MyCursor(double x, double y) : myX(x), myY(y)
{
  
}

void MyCursor::curmove(double x, double y)
{
  move(y, x);
  myX = x;
  myY = y;
}


void MyCursor::mycursor(char num_move)
{
  if (num_move == 'h')
    this -> curmove(myX - 1, myY);
  else if (num_move == 'j')
    this -> curmove(myX, myY + 1);
  else if (num_move == 'k')
    this -> curmove(myX, myY - 1);
  else if (num_move == 'l')
    this -> curmove(myX + 1, myY);
}

