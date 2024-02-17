#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  long long N, M, K;
  cin >> N >> M >> K;
  long long L = lcm(N, M);
  const long long INF = 4e18;

  auto f = [&](long long X) {
    long long a = X / N;
    long long b = X / M;
    long long c = X / L;
    return a + b - c * 2;
  };

  auto g = [&](long long X) {
    return f(X) - K;
  };
  
  long long right = INF;  // OK
  long long left = 0;  // NG
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    long long now = g(mid);
    if (now >= 0) { // OK
      right = mid;
    } else {
      left = mid;
    }
  }
  long long ans = right;
  cout << ans << endl;
  return 0;
}
