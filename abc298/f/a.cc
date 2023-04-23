#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, const T b) { a = max(a, b); }

// Coordinate compression
// https://github.com/atcoder/live_library/blob/master/cc.cpp
// 圧縮後の値は0からN-1 (Nはsize())
#include <algorithm>
template<typename T=int> struct CC {
  bool initialized;
  vector<T> xs;
  CC() : initialized(false) {}
  void add(T x) { xs.push_back(x); }
  void init() {  // O(Nlog(N))
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    initialized = true;
  }
  int operator()(T x) {  // 圧縮前の値から圧縮後の値を得る。O(logN)
    if (!initialized) { init(); }
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }
  T operator[](int i) {  // 圧縮後の値から圧縮前の値を得る。O(1)
    if (!initialized) { init(); }
    return xs[i];
  }
  int size() {
    if (!initialized) { init(); }
    return xs.size();
  }
};

int main() {
  int N;
  cin >> N;
  CC cc_r, cc_c;
  vector<int> R(N), C(N), val(N);
  for (int n = 0; n < N; n++) {
    cin >> R.at(n) >> C.at(n) >> val.at(n);
    cc_r.add(R.at(n));
    cc_c.add(C.at(n));
  }
  int H = cc_r.size();
  int W = cc_c.size();
  vector<long long> S(H, 0), T(W, 0);
  vector<set<int> > xs(H);
  for (int n = 0; n < N; n++) {
    int y = cc_r(R[n]);
    int x = cc_c(C[n]);
    S[y] += val[n];
    T[x] += val[n];
    xs[y].insert(x);
  }

  long long ans = 0;
  // 1
  for (int n = 0; n < N; n++) {
    int y = cc_r(R[n]);
    int x = cc_c(C[n]);
    long long now = S[y] + T[x] - val[n];
    chmax(ans, now);
  }
  // 2
  vector<pair<long long, int> > U(W + 1);
  for (int x = 0; x < W; x++) {
    U[x] = make_pair(T[x], x);
  }
  U[W] = make_pair(0, -1);
  sort(U.rbegin(), U.rend());
  for (int y = 0; y < H; y++) {
    for (int i = 0; i <= W; i++) {
      int x = U[i].second;
      if (xs[y].count(x) > 0) {
        continue;
      }
      long long now = S[y] + U[i].first;
      chmax(ans, now);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
