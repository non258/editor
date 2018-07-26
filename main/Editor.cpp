#include "MyCursor.hpp"
#include "Frame.hpp"
#include "Window.hpp"
#include "TextLine.hpp"
#include "Editor.hpp"

using namespace std;

void Editor::newpage()
{
  lines.push_back(shared_ptr<TextLine>(new TextLine()));
}

void Editor::addChar(char c, MyCursor &cur)
{
  int x = (int)cur.myX, y = (int)cur.myY;

  lines[y] -> inputChar(x, c);

  cur.curmove(RIGHT);
}

void Editor::eraseChar(MyCursor &cur)
{
  int x = (int)cur.myX, y = (int)cur.myY;
  if (x == 0 && y == 0)
    return;
  if (x == 0)
  {
    lines.erase(lines.begin() + y);
    cur.curmove(UP, *this);
    cur.myX = lines[(int)cur.myY] -> st.size();
  }
  else
  {
    lines[y] -> st.erase(lines[y] -> st.begin() + x - 1);
    cur.curmove(LEFT, *this);
  }
}

void Editor::viewText()
{
  string s = lines[viewY] -> asString();
  for (int i = 1; i < Window::terY; i++)
  {
    if (i + viewY >= (int)lines.size())
      break;
    s += "\n" + (lines[i + viewY] -> asString());
  }
  clear();
  char text[s.length()+1]; // Char配列の定義
  strcpy(text, s.c_str()); // String -> Char
  printw(text);
}

bool Editor::isEnter(char c)
{
  return c == 10;
}

bool Editor::isBackSpace(char c)
{
  return c == 7;
}

void Editor::newLine(MyCursor &cur)
{
  int x = cur.myX, y = cur.myY;
  auto split = lines[y] -> splitLine(x);
  lines[y] = shared_ptr<TextLine>(new TextLine(split.first));
  lines.insert(lines.begin() + y + 1, shared_ptr<TextLine>(new TextLine(split.second)));
  cur.myX = 0;
  cur.curmove(DOWN, *this);
}

int Editor::getHeight()
{
  return (int)lines.size();
}

int Editor::getWidth(int y)
{
  return (int)(lines[y] -> st.size());
}
