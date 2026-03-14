#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long L, R, D, U;
  cin >> L >> R >> D >> U;
  long long ans = 0;
  for (int x = L; x <= R; x++) {
    for (int y = D; y <= U; y++) {
      int now = max(abs(x), abs(y));
      if (now % 2 == 0) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
