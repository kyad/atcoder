#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  bool ans = false;
  while (true) {
    if (X == Y * Z) {
      ans = true;
      break;
    } else if (X < Y * Z) {
      ans = false;
      break;
    }
    X++;
    Y++;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
