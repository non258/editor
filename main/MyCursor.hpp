#ifndef MYCURSOR_HEADER
#define MYCURSOR_HEADER

class Editor;

#define UP      1
#define DOWN    2
#define LEFT    3
#define RIGHT   4
using namespace std;


class MyCursor 
{
  public:
    double myX;
    double myY;
//    Frame frame;
  MyCursor(double x, double y);
//  bool checkTouchFrame(double x, double y);
  void redraw();
  void curmove(int udlr);
  void curmove(int udlr, Editor &edi);
  void mycursor(char num_move, Editor &edi);
  void inputText(char chtxt);
  void enter(char enter);
  bool isMove(char c);
};

#endif
