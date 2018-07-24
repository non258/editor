#ifndef EITOR_HEADER
#define EITOR_HEADER

#include <memory>
#include <vector>
#include <string>
#include <cstring>
#include <ncurses.h>

#include "TextLine.hpp"
#include "MyCursor.hpp"
using namespace std;

class Editor
{
  private:
    vector<shared_ptr<TextLine>> lines;
  public:
    int viewY = 0;
    void addChar(char c, MyCursor &cur);
    void viewText();
    void newpage();
    bool isEnter(char c);
    void newLine(MyCursor &obj);
};

#endif

