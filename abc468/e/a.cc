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

using Prob = mint;

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i);
  }
  vector<mint> S(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    S.at(i) = S.at(i - 1) + A.at(i);
  }

  Prob ans = 0;
  mint sum = 0;
  for (int l = 1; l <= (N + 1) / 2; l++) {
    int r = N + 1 - l;
    sum += S.at(r) - S.at(l - 1);
    ans += sum / l;
    if (l != r) {
      ans += sum / r;
    }
  }
  cout << ans << '\n';
  return 0;
}
