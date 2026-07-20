#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  int l = 0;
  int ans = 0;
  while (l < N) {
    int mode = 1;
    int i = l;
    int r;
    while (true) {
      int ni = i + 1;
      if (ni >= N) {
        break;
      }
      if (mode == 1) {
        if (H.at(i) < H.at(ni)) {
          i = ni;
        } else if (H.at(i) == H.at(ni)) {
          mode = 3;
          r = i;
          break;
        } else {
          mode = 2;
          i = ni;
        }
      } else {
        assert(mode == 2);
        if (H.at(i) <= H.at(ni)) {
          mode = 3;
          r = i;
          break;
        } else {
          i = ni;
        }
      }
    }
    if (mode != 3) {
      r = N - 1;
      mode = 3;
    }
    // ここまでで、[l, r]は条件を見たす最大の範囲
    int hmax = *max_element(H.begin() + l, H.begin() + r + 1);
    int hmin = *min_element(H.begin() + l, H.begin() + r + 1);
    if (hmax - hmin >= K) {
      int now = r - l + 1;
      ans = max(ans, now);
    }
    if (l == r) {
      l = r + 1;
    } else {
      l = r;
    }
  }
  cout << ans << '\n';
  return 0;
}
