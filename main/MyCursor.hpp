#ifndef MYCURSOR_HEADER
#define MYCURSOR_HEADER

class MyCursor 
{
  public:
    double myX;
    double myY;
  MyCursor(double x, double y);
  void curmove(double x, double y);
  void mycursor(char num_move);
};

#endif
