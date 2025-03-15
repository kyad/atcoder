#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

using lll = __int128;

int main() {
  long long n;
  cin >> n;
  lll N = n;
  for (lll d = 1; d <= 1000000; d++) {
    auto f = [&](lll y) {
      lll ans = d * y * y * 3;
      ans += d * d * y * 3;
      ans += (d * d * d - N);
      return ans;
    };
    auto check = [&](lll y) {
      return f(y) >= 0;
    };
    lll left = 0;  // NG
    lll right = 1e9 + 1;  // OK
    while (right - left > 1) {
      lll mid = (left + right) / 2;
      if (check(mid)) {
        right = mid;
      } else {
        left = mid;
      }
    }
    if (f(right) == 0) {
      lll y = right;
      lll x = y + d;
      cout << (long long)x << ' ' << (long long)y << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
