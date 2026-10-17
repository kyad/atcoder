#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<string> S(2);
  for (int y = 0; y < 2; y++) {
    cin >> S.at(y);
  }
  int ay = -1, ax = -1;
  int dy = -1, dx = -1;
  for (int y = 0; y < 2; y++) {
    for (int x = 0; x < 2; x++) {
      if (S.at(y).at(x) == 'A') {
        ay = y;
        ax = x;
      } else if (S.at(y).at(x) == 'D') {
        dy = y;
        dx = x;
      }
    }
  }
  bool ans = false;
  if (ay == dy || ax == dx) {
    ans = true;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
