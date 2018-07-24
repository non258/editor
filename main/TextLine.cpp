#include "MyCursor.hpp"
#include "Frame.hpp"
#include "Window.hpp"
#include "TextLine.hpp"

using namespace std;

TextLine::TextLine()
{

}

TextLine::TextLine(vector<char> v)
{
  st = v;
}


void TextLine::inputChar(int x, char c)
{
  st.insert(st.begin() + x, c);
}

string TextLine::asString()
{
  string s = "";

  for (int i = 0; i < (int)st.size(); i++)
    s += st[i];
  return s;
}

pair<vector<char>, vector<char>> TextLine::splitLine(int x)
{
  if (x == (int)st.size())
    return {st, vector<char>()};
  vector<char> v1(st.begin(), st.begin() + x);
  vector<char> v2(st.begin() + x, st.end());


  return {v1, v2};
}
