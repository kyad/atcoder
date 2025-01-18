#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long R;
  cin >> R;
  long long sum = 0;
  for (long long i = 1; i < R; i++) {
    long long right = R;  // NG
    long long left = 0;  // OK
    
    auto check = [&](long long k) {
      return (i * 2 + 1) * (i * 2 + 1) + (k * 2 + 1) * (k * 2 + 1) <= R * R * 4;
    };

    while (right - left > 1) {
      long long mid = (left + right) / 2;
      if (check(mid)) {
        left = mid;
      } else {
        right = mid;
      }
    }
    sum += left;
  }
  long long ans = (sum + R - 1) * 4 + 1;
  cout << ans << endl;
  return 0;
}
