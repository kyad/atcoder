#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int M, A, B;
  cin >> M >> A >> B;
  // color[1個前][2個前]
  // -1: 未確定
  // 0: Mの倍数でないことが確定
  // 1: Mの倍数になることが確定
  vector<vector<int> > color(M, vector<int>(M, -1));
  for (int x = 0; x <= M - 1; x++) {  // 2個前
    for (int y = 0; y <= M - 1; y++) {  // 1個前
      int s = ((A * y) % M + (B * x) % M) % M;
      if (x % M == 0 || y % M == 0 || s == 0) {
        color.at(y).at(x) = 1;
      }
    }
  }
  vector<vector<bool> > visited(M, vector<bool>(M, false));
  // y=1個前、x=2個前
  auto f = [&](auto f, int y, int x) -> int {
    if (color.at(y).at(x) >= 0) {
      visited.at(y).at(x) = true;
      return color.at(y).at(x);
    }
    if (visited.at(y).at(x)) {
      visited.at(y).at(x) = true;
      return color.at(y).at(x) = 0;
    }
    int s = ((A * y) % M + (B * x) % M) % M;
    if (s == 0) {
      visited.at(y).at(x) = true;
      return color.at(y).at(x) = 1;
    }
    visited.at(y).at(x) = true;
    return color.at(y).at(x) = f(f, s, y);
  };
  for (int x = 0; x <= M - 1; x++) {  // 2個前
    for (int y = 0; y <= M - 1; y++) {  // 1個前
      if (color.at(y).at(x) == -1) {
        f(f, y, x);
      }
    }
  }
  int ans = 0;
  for (int x = 0; x <= M - 1; x++) {  // 2個前
    for (int y = 0; y <= M - 1; y++) {  // 1個前
      if (color.at(y).at(x) == 0) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
