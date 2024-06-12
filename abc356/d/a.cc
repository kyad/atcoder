// https://www.youtube.com/watch?v=CEKxg0VQtxg&t=2256s

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

int main() {
  long long N, M;
  cin >> N >> M;
  mint ans = 0;
  for (int i = 0; i <= 59; i++) {
    if ((M>>i&1) == 0) {
      continue;
    }
    long long p = 1LL<<(i + 1);
    long long q = (N + 1) / p;
    long long r = (N + 1) % p;
    mint now = q * p / 2;
    if (r > p / 2) {
      now += r - p / 2;
    }
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
