// https://www.youtube.com/watch?v=gK_iG4jFCgg

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <tuple>
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
  long long N;
  cin >> N;
  N++;
  vector<int> digits;
  while (N > 0) {
    digits.push_back(N % 2);
    N /= 2;
  }
  reverse(digits.begin(), digits.end());

  const int M = 3;
  vector<int> A(M);
  for (int m = 0; m < M; m++) {
    cin >> A.at(m);
  }

  using T = tuple<int, bool, bool>;  // Residual, Smaller, non-Zero
  using VT = vector<T>;
  map<VT, mint> dp;
  dp[VT(3)] = 1;
  for (int d : digits) {
    map<VT, mint> p;
    swap(dp, p);
    for (int bit = 0; bit < (1<<M); bit++) {
      vector<int> b(M);
      int xor_b = 0;
      for (int m = 0; m < M; m++) {
        b[m] = bit>>m&1;
        xor_b ^= b[m];
      }
      if (xor_b != 0) {
        continue;
      }
      for (auto [vt, value] : p) {
        bool ok = true;
        VT nvt(3);
        for (int m = 0; m < M; m++) {
          int pr = get<0>(vt[m]);
          int nr = (2 * pr + b[m]) % A[m];
          bool ps = get<1>(vt[m]);
          bool ns;
          if (ps) {
            ns = true;
          } else {
            if (b[m] == d) {
              ns = false;
            } else if (b[m] < d) {
              ns = true;
            } else {
              // そのような遷移は無い
              ok = false;
              break;
            }
          }
          bool pz = get<2>(vt[m]);
          bool nz;
          if (pz) {
            nz = true;
          } else {
            if (b[m]) {
              nz = true;
            } else {
              nz = false;
            }
          }
          nvt[m] = {nr, ns, nz};
        }
        if (!ok) {
          continue;
        }
        dp[nvt] += value;
      }
    }
  }
  mint ans = dp[VT(3, {0, true, true})];
  cout << ans << endl;
  return 0;
}
