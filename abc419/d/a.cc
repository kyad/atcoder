#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

// 区間加算・区間最大値
using S = long long;
using F = long long;
S op(S a, S b){ return std::max(a, b); }
S e(){ return 0; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
  int N, M;
  cin >> N >> M;
  string SS;
  cin >> SS;
  string TT;
  cin >> TT;
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(N);
  for (int j = 0; j < M; j++) {
    int L, R;
    cin >> L >> R;
    L--;
    seg.apply(L, R, 1);
  }
  string ans;
  for (int i = 0; i < N; i++) {
    int a = seg.get(i);
    if (a % 2 == 0) {
      ans.push_back(SS.at(i));
    } else {
      ans.push_back(TT.at(i));
    }
  }
  cout << ans << endl;
  return 0;
}
