#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X, Y, Z;
  cin >> N >> X >> Y >> Z;
  bool ans = false;
  if (X < Y) {
    if (X < Z && Z < Y) {
      ans = true;
    }
  } else {
    if (Y < Z && Z < X) {
      ans = true;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
