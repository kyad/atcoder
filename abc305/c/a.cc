#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  const int INF = 1000;
  int y0 = INF;
  int y1 = -INF;
  int x0 = INF;
  int x1 = -INF;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S[y][x] == '#') {
        y0 = min(y0, y);
        x0 = min(x0, x);
        y1 = max(y1, y);
        x1 = max(x1, x);
      }
    }
  }
  for (int y = y0; y <= y1; y++) {
    for (int x = x0; x <= x1; x++) {
      if (S[y][x] == '.') {
        cout << y + 1 << ' ' << x + 1 << endl;
        return 0;
      }
    }
  }
  assert(false);
  return 0;
}
