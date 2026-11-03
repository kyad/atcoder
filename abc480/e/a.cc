// https://www.youtube.com/watch?v=WzIF5yupzpo&t=5071s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N;
  cin >> N;
  long long ans = 0;
  for (long long a = 1; a <= 1e6; a++) {
    for (int n = 3; n <= 20; n++) {
    {
      long long m = N;
      for (int i = 0; i < n; i++) {
        m /= a;
      }
      if (m == 0) {
        break;
      }
    }
    long long left = 0;  // OK
    long long right = 1e9; // NG
    auto check = [&](long long d) {
      long long m = N;
      for (int i = 0; i < n; i++) {
        m /= (a + d * i);
      }
      if (m == 0) {
        return false;
      } else {
        return true;
      }
    };
    while (right - left > 1) {
      long long mid = (left + right) / 2;
      if (check(mid)) {
        left = mid;
      } else {
        right = mid;
      }
    }
    ans += left;
    }
  }
  cout << ans << '\n';
  return 0;
}
