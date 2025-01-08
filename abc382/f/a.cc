#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

// 区間変更・区間最小値取得
using S = int;  // 要素
using F = int;  // 写像
const S INF = 1e9;
const F ID = 1e9;  // 取りえない値を設定
S op(S a, S b){ return std::min(a, b); }  // 写像
S e(){ return INF; }  // 写像の単位元
S mapping(F f, S x){ return (f == ID ? x : f); }  // 写像を要素に適用したものを返す
F composition(F f, F g){ return (f == ID ? g : f); }  // 合成写像を返す。gを先に適用してfを後で適用する。
F id(){ return ID; }  // 恒等写像

void print_lazy_segtree(int N, lazy_segtree<S, op, e, F, mapping, composition, id> &seg) {
  vector<S> v(N);
  for (int n = 0; n < N; n++) { v.at(n) = seg.get(n); }
  cerr << '[';
  for (int i = 0; i < N; i++) {
    //cerr << '['<< i << ']=';
    cerr << v[i];
    //cerr << v[i].value;  // 区間和の時
    const int MOD = -1;
    if (i == N - 1) { continue; }
    else if (MOD > 0 && i % MOD == (MOD - 1)) { cerr << '\n'; }
    else { cerr << ' '; }
  }
  cerr << ']' << endl;
}

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<tuple<int, int, int, int> > data(N);
    for (int i = 0; i < N; i++) {
        int R, C, L;
        cin >> R >> C >> L;
        C--;
        data.at(i) = make_tuple(R, C, L, i);
    }
    // セグ木は全部Hで初期化する
    const int MX = 2e5;
    vector<int> A(MX, H);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);
    sort(data.begin(), data.end(), greater<tuple<int, int, int, int> >());  // y座標が大きい順に処理する
    vector<int> ans(N, -1);
    for (int i = 0; i < N; i++) {
        int R, C, L, idx;
        tie(R, C, L, idx) = data.at(i);
        ans.at(idx) = seg.prod(C, C + L);
        seg.apply(C, C + L, ans.at(idx) - 1);
    }
    for (int i = 0; i < N; i++) {
        cout << ans.at(i) << endl;
    }
    return 0;
}
