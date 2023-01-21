// https://atcoder.jp/contests/abc285/tasks/abc285_f

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/fenwicktree>
using namespace atcoder;
using BIT = fenwick_tree<int>;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  BIT cmp(N);
  vector<BIT> count(26, BIT(N));
  for (int n = 0; n < N - 1; n++) {
    if (S[n] > S[n + 1]) {
      cmp.add(n, 1);
    }
  }
  for (int n = 0; n < N; n++) {
    count[S[n] - 'a'].add(n, 1);
  }
  int Q;
  cin >> Q;

  auto add = [&](int i, int x) {
    count[S[i] - 'a'].add(i, x);
    if (i >= 1 && S[i - 1] > S[i]) {
      cmp.add(i - 1, x);
    }
    if (i < N - 1 && S[i] > S[i + 1]) {
      cmp.add(i, x);
    }
  };

  for (int q = 0; q < Q; q++) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int x;
      char c;
      cin >> x >> c;
      x--;
      add(x, -1);
      S[x] = c;
      add(x, +1);
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      bool ans = true;
      if (cmp.sum(l, r - 1) != 0) {
        ans = false;
      }
      for (int i = S[l] - 'a' + 1; i < S[r - 1] - 'a'; i++) {
        if (count[i].sum(l, r) != count[i].sum(0, N)) {
          ans = false;
        }
      }
      cout << (ans ? "Yes" : "No") << endl;
    }
  }
  return 0;
}
