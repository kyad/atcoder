// https://www.youtube.com/watch?v=rzPy_MyIv6M&t=5890s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long INF = 2e9+2;

int main() {
  int N;
  long long X;
  cin >> N >> X;
  vector<long long> U(N), D(N);
  for (int i = 0; i < N; i++) {
    cin >> U.at(i) >> D.at(i);
  }
  const long long INF = 1e18;
  auto check = [&](long long H) {
    long long r = INF;
    long long l = -INF;
    for (int i = 0; i < N; i++) {
      r = min(r + X, U.at(i));
      l = max(l - X, H - D.at(i));
      if (r < l) {
        return false;
      }
    }
    return true;
  };
  long long left = 0;  // OK
  long long right = INF;  // NG
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    if (check(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  long long H = left;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += U.at(i);
    ans += D.at(i);
  }
  ans -= H * N;
  cout << ans << endl;
  return 0;
}
