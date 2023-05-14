#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
// modint
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}

void testcase() {
  long long N;
  cin >> N;
  mint ans = 0;
  for (long long x = 1; x * x <= N; x++) {
    for (long long y = x; y * y <= N; y++) {
      // z == y
      if (x == y) {
        ans += 1;
      } else {
        ans += 3;
      }
      // z = y + 1, ..., sqrt(N)
      if (x == y) {
        ans += ((N / y) - y) * 3;
      } else {
        ans += ((N / y) - y) * 6;
      }
    }
  }
  cout << ans.val() << endl;
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    testcase();
  }
  return 0;
}
