#include <iostream>
#include <map>
#include <vector>
using namespace std;
#include <atcoder/lazysegtree>
using namespace atcoder;

// 最大値取得・範囲更新
using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main() {
  int W, N;
  cin >> W >> N;
  vector<int> L(N), R(N);
  map<int, int> enc;
  // Compression
  for (int n = 0; n < N; n++) {
    cin >> L.at(n) >> R.at(n);
    enc[L.at(n)] = -1;
    enc[R.at(n)] = -1;
  }
  int sz = 0;
  map<int, int> dec;
  for (auto& p : enc) {
    p.second = sz;
    dec[sz] = p.first;
    sz++;
  }
  // Segtree
  std::vector<S> v(sz, 0LL);
  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
  for (int n = 0; n < N; n++) {
    int l = enc[L[n]];
    int r = enc[R[n]];
    S mx = seg.prod(l, r + 1);
    S now = mx + 1;
    cout << now << endl;
    seg.apply(l, r + 1, now);
  }
  return 0;
}
