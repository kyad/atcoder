#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long L, R;
  cin >> L >> R;
  long long ans = -1;
  for (long long delta = 0; delta <= R - L; delta++) {
    for (long long x = L; x <= L + delta; x++) {
      long long y = x + (R - L - delta);
      if (__gcd(x, y) == 1) {
        ans = R - L - delta;
        goto end;
      }
    }
  }
 end:
  cout << ans << endl;
  return 0;
}
