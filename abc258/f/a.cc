// https://atcoder.jp/contests/abc258/tasks/abc258_f

#include <iostream>
#include <vector>
using namespace std;

// マンハッタン距離
inline long long man(long long sx, long long sy, long long gx, long long gy) {
  return abs(sx - gx) + abs(sy - gy);
}

void testcase() {
  long long B, K, SX, SY, GX, GY;
  cin >> B >> K >> SX >> SY >> GX >> GY;
  long long ans = man(SX, SY, GX, GY) * K;  // 大通りを使わない場合

  // 大通りを使う場合
  for (int sv = 0; sv < 4; sv++) {
    for (int gv = 0; gv < 4; gv++) {
      long long now = 0;
      long long sx = SX;
      long long sy = SY;
      long long gx = GX;
      long long gy = GY;
      // 大通りに移動する
      auto move1 = [&](long long &x, long long &y, int v) {
        auto move1x = [&](long long &x, int v) {
          long long nx = x / B * B;
          if (v) {
            nx += B;
          }
          now += abs(nx - x) * K;
          x = nx;
        };
        if (v < 2) {
          move1x(x, v);
        } else {
          move1x(y, v - 2);
        }
      };
      move1(sx, sy, sv);
      move1(gx, gy, gv);
      // 大通り間を移動する
      auto move2 = [&](long long sx, long long sy, long long gx, long long gy) -> long long {
        long long m = man(sx, sy, gx, gy);
        if (sy % B == 0) {  // sx % B == 0の場合に変換して考える
          swap(sx, sy);
          swap(gx, gy);
        }
        if (gx % B) {
          return m;
        }
        if (sy / B != gy / B) {
          return m;
        }
        if (sx == gx) {
          return m;
        }
        long long r = sy % B + gy % B;
        return min(r, B * 2 - r) + abs(sx - gx);
      };
      now += move2(sx, sy, gx, gy);
      ans = min(ans, now);
    }
  }
  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    testcase();
  }
  return 0;
}
