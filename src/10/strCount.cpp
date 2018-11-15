#include "strCount.h"

int main() {

  MyStr inWord;
  map<MyStr, int> mStr;
  while (cin >> inWord) {
    if (mStr.find(inWord) != mStr.end())
      ++mStr[inWord];
    else
      mStr[inWord] = 1;
  }

  for (auto &item : mStr)
    cout << item.first << "  " << item.second << endl;
}
