#include "Window.hpp"

#ifndef FRAME_HEADER
#define FRAME_HEADER

class Frame
{
  public:
    double frameX;
    double frameY;
    Window window;
  Frame(double x, double y);
  bool checkCursor(double x, double y);
  void popFrame(Window w);
};

#endif
