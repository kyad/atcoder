#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// modint
#include <atcoder/modint>
using namespace atcoder;
using mint = modint;
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}

int main() {
  int N, Q, M;
  cin >> N >> Q >> M;
  mint::set_mod(M);
  vector<int> P(N);
  int count = 0;
  int x0 = -1;
  for (int i = 0; i < N; i++) {
    cin >> P.at(i);
    if (P.at(i) % M == 0) {
      count++;
      x0 = i;
    }
  }
  mint prod = 1;
  if (count == 0) {
    for (int i = 0; i < N; i++) {
      prod *= P.at(i);
    }
  } else if (count == 1) {
    for (int i = 0; i < N; i++) {
      if (i == x0) {
        continue;
      }
      prod *= P.at(i);
    }
  }
  for (int qi = 0; qi < Q; qi++) {
    int X, V;
    cin >> X >> V;
    X--;
    mint ans;
    if (count >= 2) {
      ans = 0;
    } else if (count == 1) {
      if (X != x0) {
        ans = 0;
      } else {
        ans = prod * V;
      }
    } else {
      ans = prod / P.at(X) * V;
    }
    cout << ans << '\n';
  }
  return 0;
}
