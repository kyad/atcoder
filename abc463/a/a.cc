#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int X, Y;
  cin >> X >> Y;
  bool ans = 9 * X == 16 * Y;
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
