#include "Frame.hpp"

#ifndef MYCURSOR_HEADER
#define MYCURSOR_HEADER

class MyCursor 
{
  public:
    double myX;
    double myY;
    Frame frame;
  MyCursor(double x, double y, Frame f);
  void curmove(int udlr);
  void mycursor(char num_move);
  bool checkTouchFrame(double x, double y);
};

#endif
