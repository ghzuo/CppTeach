#ifndef STRCOUNT_H
#define STRCOUNT_H

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

struct MyStr : string {
  friend istream &operator>>(istream &is, MyStr &v) {
    string str;
    is >> str;
    sort(str.begin(), str.end());
    v.swap(str);
    return is;
  };
};

#endif
