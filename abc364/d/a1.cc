#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());

  for (int qi = 0; qi < Q; qi++) {
    int B, K;
    cin >> B >> K;

    // Bから距離d以下にK個以上あるか？
    auto judge = [&](int d) -> bool {
      int num = lower_bound(A.begin(), A.end(), B + d + 1) - lower_bound(A.begin(), A.end(), B - d);
      return num >= K;
    };

    int left = -1;  // NG
    int right = 4e8;  // OK
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (judge(mid) == true) {
        right = mid;
      } else {
        left = mid;
      }
    }
    int ans = right;
    cout << ans << '\n';
  }
  return 0;
}
