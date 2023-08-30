// https://twitter.com/e869120/status/1412904274900754441

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
// modint
#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> X(Q), Y(Q), Z(Q);
  vector<long long> W(Q);
  for (int q = 0; q < Q; q++) {
    cin >> X[q] >> Y[q] >> Z[q] >> W[q];
    X[q]--; Y[q]--; Z[q]--;
  }
  mint ans = 1;
  int N2 = 1<<N;
  for (int i = 0; i < 60; i++) {
    mint now = 0;
    for (int s = 0; s < N2; s++) {  // Aのi桁目を全探索
      bool ok = true;
      for (int q = 0; q < Q; q++) {
        int x = s>>(X[q])&1;
        int y = s>>(Y[q])&1;
        int z = s>>(Z[q])&1;
        int w = (W[q])>>i&1;
        int l = x | y | z;
        if (l != w) {
          ok = false;
          break;
        }
      }
      if (ok) {
        now++;
      }
    }
    ans *= now;
  }
  cout << ans.val() << endl;
  return 0;
}
