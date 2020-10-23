#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  /* read the list file, please careful check the # in the list file */
  ifstream fp("list.txt");
  for (string line; getline(fp, line);) {
    line = line.substr(0, line.find_first_of("#"));
    if (!line.empty())
      cout << line << endl;
  }
  fp.close();
}
