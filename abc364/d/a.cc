#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  sort(A.begin(), A.end());
  for (int qi = 0; qi < Q; qi++) {
    long long B;
    int K;
    cin >> B >> K;
    
    // 「距離がd以下のものがk個以上ある」を満たす最小のdが答
    long long right = 2e8+10;  // OK
    long long left = -1;  // NG
    
    while (right - left > 1) {
      long long mid = (left + right) / 2;  // d
      const long long d = mid;
      int U = upper_bound(A.begin(), A.end(), B + d) - A.begin();
      int L = lower_bound(A.begin(), A.end(), B - d) - A.begin();
      int now = U - L;  // 距離がd以下の個数
      if (now >= K) {
        right = mid;  // OK
      } else {
        left = mid;  // NG
      }
    }
    long long ans = right;
    cout << ans << '\n';
  }
  return 0;
}
