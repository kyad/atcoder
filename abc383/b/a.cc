#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W, D;
  cin >> H >> W >> D;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  int ans = 0;
  for (int y0 = 0; y0 < H; y0++) { // 加湿器0のマス
    for (int x0 = 0; x0 < W; x0++) {
      if (S[y0][x0] != '.') {
        continue;
      }
      for (int y1 = 0; y1 < H; y1++) { // 加湿器1のマス
        for (int x1 = 0; x1 < W; x1++) {
          if (S[y1][x1] != '.') {
            continue;
          }
          if (y0 == y1 && x0 == x1) {
            continue;
          }
          // 加湿されるマスを数える
          int now = 0;
          for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
              if (S[y][x] != '.') {
                continue;
              }
              if ((abs(y0 - y) + abs(x0 - x) <= D) ||
                  (abs(y1 - y) + abs(x1 - x) <= D)) {
                now++;
              }
            }
          }
          ans = max(ans, now);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
