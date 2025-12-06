#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

// lazy_segtree<S, op, e, F, mapping, composition, id> seg(N);  // eで初期化
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);  // 配列Aで初期化
// seg.prod(l, r)  // [l, r)にopを適用。l==rの時はe()を返す。r>=Nの時はassertエラー。
// S ans = seg.all_prod();
// seg.apply(l, r, f)  // [l, r)にfを適用
// seg.get(i)  // O(logN)
// seg.set(i, x);  // O(logN)

// 区間変更・区間和 (構造体で持つ)
struct S{
    long long value;
    int size;
};
using F = long long;
const F ID = 8e18;
S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){
    if(f != ID) x.value = f*x.size;
    return x;
}
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }


void print_lazy_segtree(int N, lazy_segtree<S, op, e, F, mapping, composition, id> &seg) {
  vector<S> v(N);
  for (int n = 0; n < N; n++) { v.at(n) = seg.get(n); }
  cerr << '[';
  for (int i = 0; i < N; i++) {
    //cerr << '['<< i << ']=';
    //cerr << v[i];
    cerr << v[i].value;  // 区間和の時
    const int MOD = -1;
    if (i == N - 1) { continue; }
    else if (MOD > 0 && i % MOD == (MOD - 1)) { cerr << '\n'; }
    else { cerr << ' '; }
  }
  cerr << ']' << endl;
}


int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> L(Q), R(Q);
  set<int> st;
  st.insert(1);
  st.insert(N + 1);
  for (int qi = 0; qi < Q; qi++) {
    cin >> L.at(qi) >> R.at(qi);
    st.insert(L.at(qi));
    st.insert(R.at(qi) + 1);
  }
  vector<int> xs;
  for (int x : st) {
    xs.push_back(x);
  }
  int M = xs.size();
  map<int, int> x_to_j;
  for (int j = 0; j < M; j++) {
    x_to_j[xs.at(j)] = j;
  }
  vector<S> v(M);
  for (int j = 0; j < M - 1; j++) {
    v.at(j).value = xs.at(j + 1) - xs.at(j);
    v.at(j).size = 1;
  }
  v.at(M - 1).value = 0;
  v.at(M - 1).size = 0;
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
  for (int qi = 0; qi < Q; qi++) {
    int l = x_to_j[L.at(qi)];
    int r = x_to_j[R.at(qi) + 1];
    seg.apply(l, r, 0);
    long long ans = seg.prod(0, M).value;
    cout << ans << '\n';
  }
  return 0;
}
