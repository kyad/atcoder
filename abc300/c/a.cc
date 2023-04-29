#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> C(H);
  for (int y = 0; y < H; y++) {
    cin >> C.at(y);
  }
  int r_max = min((H - 1) / 2, (W - 1) / 2);
  const int dy[2] = {1, 1};
  const int dx[2] = {1, -1};
  auto check = [&](int cy, int cx, int r) -> bool {
    if (C[cy][cx] == '.') {
      return false;
    }
    bool ans = true;
    for (int k = 0; k < 2; k++) {
      for (int i = -r; i <= r; i++) {
        int y = cy + dy[k] * i;
        int x = cx + dx[k] * i;
        assert(0 <= y && y < H);
        assert(0 <= x && x < W);
        if (C[y][x] == '.') {
          ans = false;
          break;
        }
      }
      if (ans == false) {
        break;
      }
    }
    return ans;
  };
  auto fill = [&](int cy, int cx, int r) {
    C[cy][cx] = '.';
    for (int k = 0; k < 2; k++) {
      for (int i = -r; i <= r; i++) {
        int y = cy + dy[k] * i;
        int x = cx + dx[k] * i;
        assert(0 <= y && y < H);
        assert(0 <= x && x < W);
        C[y][x] = '.';
      }
    }
  };
  int N = min(H, W);
  vector<int> S(N + 1, 0);
  for (int r = r_max; r >= 1; r--) {
    for (int cy = r; cy <= H - 1 - r; cy++) {
      for (int cx = r; cx <= W - 1 - r; cx++) {
        if (check(cy, cx, r) == true) {
          S[r]++;
          fill(cy, cx, r);
        }
      }
    }
  }
  for (int n = 1; n <= N; n++) {
    cout << S[n] << " \n"[n == N];
  }
  return 0;
}
