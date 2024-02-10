#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

// 区間加算・区間和 (構造体で持つ)
struct S {
  long long value;
  int size;
};
using F = long long;

S op(S a, S b){ return {a.value + b.value, a.size + b.size}; }
S e(){ return {0, 0};}
S mapping(F f, S x){ return {x.value + f * x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);
// seg.apply(l, r, value);
// S ans = seg.all_prod();


void print_lazy_segtree(int N, lazy_segtree<S, op, e, F, mapping, composition, id> &seg) {
  vector<S> v(N);
  for (int n = 0; n < N; n++) { v.at(n) = seg.get(n); }
  cerr << '[';
  for (int i = 0; i < N; i++) {
    //cerr << '['<< i << ']=';
    cerr << v[i].value;
    const int MOD = -1;
    if (i == N - 1) { continue; }
    else if (MOD > 0 && i % MOD == (MOD - 1)) { cerr << '\n'; }
    else { cerr << ' '; }
  }
  cerr << ']' << endl;
}

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

S zero(){ return {0, 1};}

int main() {
  int N, M;
  cin >> N >> M;
  vector<S> A(N * 2);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n).value;
    A.at(n).size = 1;
  }
  for (int i = N; i < 2 * N; i++) {
    A.at(i).value = 0;
    A.at(i).size = 1;
  }
  vector<int> B(M);
  for (int m = 0; m < M; m++) {
    cin >> B.at(m);
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);

  for (int m = 0; m < M; m++) {
    int b = B.at(m);
    long long count = seg.get(b).value + seg.get(b + N).value;
    seg.set(b, zero());
    seg.set(b + N, zero());
    long long q = count / N;
    seg.apply(0, N, q);
    int res = count % N;
    int left = b + 1;
    int right = b + res + 1;
    seg.apply(left, right, 1);
  }
  vector<long long> X(N);
  for (int i = 0; i < N; i++) {
    X.at(i) = seg.get(i).value + seg.get(i + N).value;
  }
  dumpvec(X);
  return 0;
}
