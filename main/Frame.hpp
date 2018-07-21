#include "Window.hpp"

#ifndef FRAME_HEADER
#define FRAME_HEADER

/*
 * Windowに貼り付ける枠の情報をもつ
 * frameX :Frameのx軸の大きさの値をもつ
 * frameY :Frameのy軸の大きさの値をもつ
 * window :Frameを貼り付けているWindowをもつ
 */
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
