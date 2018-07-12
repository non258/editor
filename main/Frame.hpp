#ifndef FRAME_HEADER
#define FRAME_HEADER

class Frame
{
  public:
    double frameX;
    double frameY;
  Frame(double x, double y);
  void popFrame();
};

#endif
