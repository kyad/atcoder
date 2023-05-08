#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int> > P(H, vector<int>(W, -1));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cin >> P.at(y).at(x);
    }
  }
  int ans = 0;
  for (int b = 1; b < (1<<H); b++) {
    vector<int> count(H * W + 1, 0);
    for (int x = 0; x < W; x++) {
      int ok = true;
      int P0 = -1;
      for (int y = 0; y < H; y++) {
        if ((b>>y&1) == 0) {
          continue;
        }
        if (P0 < 0) {
          P0 = P[y][x];
          continue;
        }
        if (P[y][x] != P0) {
          ok = false;
          break;
        }
      }
      if (ok) {
        assert(0 < P0 && P0 <= H * W);
        count[P0] += __builtin_popcount(b);
      }
    }
    int now = *max_element(count.begin(), count.end());
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}
