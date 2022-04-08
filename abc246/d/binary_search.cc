// https://atcoder.jp/contests/abc246/tasks/abc246_d

#include <iostream>
using namespace std;

long long f(long long a, long long b) {
  return  a * a * a + a * a * b + a * b * b + b * b * b;
}

int main() {
  long long N;
  cin >> N;
  long long ans = 4e18+2;
  for (int a = 0; a <= 1000001; a++) {
    long long X = f(a, 0);
    if (X >= N) {
      ans = min(ans, X);
      continue;
    }
    // Search b s.t. f(a, b) >= N
    int left = 0;  // NG
    int right = 1000001;  // OK
    while (right - left > 1) {
      int mid = (left + right) / 2;
      long long X = f(a, mid);
      if (X >= N) {
        right = mid;
      } else {
        left = mid;
      }
    }
    ans = min(ans, f(a, right));
  }
  cout << ans << endl;
  return 0;
}
