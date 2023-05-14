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
  for (long long y = 1; y * y <= N; y++) {
    ans += (y - 1) * ((N / y) - y) * 6;
    ans += (y - 1) * 3;
    ans += ((N / y) - y) * 3;
    ans += 1;
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
