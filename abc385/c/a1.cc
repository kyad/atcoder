#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }
  int ans = 0;
  for (int k = 1; k <= N - 1; k++) {  // 間隔
    for (int i0 = 0; i0 < k; i0++) {  // スタート位置
      int prev = -1;
      int now = 0;
      for (int i = i0; i < N; i += k) {
        if (H.at(i) == prev) {
          now++;
        } else {
          prev = H.at(i);
          now = 1;
        }
        ans = max(ans, now);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
