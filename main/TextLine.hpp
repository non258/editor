#ifndef TEXTLINE_HEADER
#define TEXTLINE_HEADER

#include <random>
#include <ncurses.h>
#include <string>
#include <vector>

class TextLine 
{
  public:
    double lineY;
    vector<char> st;
  TextLine();
  TextLine(vector<char> v);
  void inputChar(int x, char c);
  string asString();
  pair<vector<char>, vector<char>> splitLine(int x);
};

#endif

