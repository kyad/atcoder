#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  int K4 = 1<<(2 * K);
  const int dy[4] = {0, -1, 0, +1};
  const int dx[4] = {+1, 0, -1, 0};
  int ans = 0;
  vector<vector<bool> > used(H, vector<bool>(W, false));  // 通ったか
  for (int bit = 0; bit < K4; bit++) {  // 進行方向
    // スタート位置
    for (int y0 = 0; y0 < H; y0++) {
      for (int x0 = 0; x0 < W; x0++) {
        if (S.at(y0).at(x0) == '#') {
          continue;
        }
        // ここからシミュレーション
        int y = y0;
        int x = x0;
        vector<int> ys, xs;
        ys.push_back(y);
        xs.push_back(x);
        used.at(y).at(x) = true;
        // 方向を考える
        bool ok = true;
        for (int k = 0; k < K; k++) {
          int a = bit>>(2 * k + 1)&1;
          int b = bit>>(2 * k)&1;
          int l = 2 * a + b;  // 方向
          assert(0 <= l && l < 4);
          y += dy[l];
          x += dx[l];
          if (y < 0 || y >= H || x < 0 || x >= W || S.at(y).at(x) == '#' || used.at(y).at(x) == true) {
            ok = false;
            break;
          }
          ys.push_back(y);
          xs.push_back(x);
          used.at(y).at(x) = true;
        }
        if (ok) {
          ans++;
        }
        // usedをクリア
        for (size_t i = 0; i < ys.size(); i++) {
          used.at(ys.at(i)).at(xs.at(i)) = false;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

