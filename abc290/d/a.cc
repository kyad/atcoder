#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// 最小公倍数
long long LCM(long long a, long long b) {
  return (long long)a / __gcd(a, b) * b;
}

void testcase() {
  long long N, D, K;
  cin >> N >> D >> K;
  D %= N;
  K--;
  long long L = LCM(N, D);
  long long p;
  if (D == 0) {
    p = 1;
  } else {
    p = L / D;
  }
  long long delta = K / p;
  long long nk = K % p;
  long long ans = (nk * D) % N;
  ans += delta;
  cout << ans << '\n';
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    testcase();
  }
  return 0;
}
