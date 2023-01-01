#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long L, R;
  cin >> L >> R;
  int X = -1;
  int Y = -1;
  long long ans = -1;
  for (long long x = L; x <= R; x++) {
    for (long long y = x + 1; y <= R; y++) {
      if (__gcd(x, y) == 1) {
        if (ans < y - x) {
          ans = y - x;
          X = x;
          Y = y;
        }
      }
    }
  }
  cout << ans << endl;
  cerr << "X=" << X << " Y=" << Y << " ans=" << ans << " delta=" << (R - L - ans) << endl;
  if (X != L && Y != R) {
    exit(1);
  }
  return 0;
}
