#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1e10;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  // AでZ以下の個数
  auto f = [&](long long Z) {
    long long ans = prev(upper_bound(A.begin(), A.end(), Z)) - A.begin();
    return ans;
  };
  for (int qi = 0; qi < Q; qi++) {
    long long X, Y;
    cin >> X >> Y;
    long long left = 0;  // NG
    long long right = INF;  // OK
    auto check = [&](long long Z) {
      long long S = f(Z) - f(X - 1);
      return Y <= (Z - X + 1 - S);
    };
    while (right - left > 1) {
      long long mid = (left + right) / 2;
      if (check(mid)) {
        right = mid;
      } else {
        left = mid;
      }
    }
    long long ans = right;
    cout << ans << '\n';
  }
  return 0;
}
