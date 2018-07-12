#ifndef FRAME_HEADER
#define FRAME_HEADER

class Frame
{
  public:
    double frameX;
    double frameY;
  Frame(double frameX, double frameY);
  double getSizeX(void);
  double getSizeY(void);
};

#endif
