#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    int N, M;
    cin >> N >> M;
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
      cin >> X.at(i);
    }
    vector<int> Y(M);
    for (int j = 0; j < M; j++) {
      cin >> Y.at(j);
    }
   
    // X, Yの要素が入ったもの
    set<int, greater<int> > st;
    for (int x : X) st.insert(x);
    for (int y : Y) st.insert(y);
    set<int, greater<int> > x0, y0;  // まだmaxを満たされていないもの
    set<int, greater<int> > x1, y1;  // maxを満たしたもの
    for (int x : X) x0.insert(x);
    for (int y : Y) y0.insert(y);
    // 重複があればNoで終了
    if ((int)x0.size() != N || (int)y0.size() != M) {
      cout << "No" << '\n';
      continue;
    }
    // x, yからindex
    vector<int> is(N * M + 1, -1);
    vector<int> js(N * M + 1, -1);
    for (int i = 0; i < N; i++) is.at(X.at(i)) = i;
    for (int j = 0; j < M; j++) js.at(Y.at(j)) = j;
    // 十分性
    vector<vector<int> > board(N, vector<int>(M, -1));
    bool ok = true;
    for (int a : st) {
      if (x0.contains(a) && y0.contains(a)) {  // X, Yの両方にaがある
        int i = is.at(a); assert(i >= 0);
        int j = js.at(a); assert(j >= 0);
        board.at(i).at(j) = a;
        x0.erase(a); x1.insert(a);
        y0.erase(a); y1.insert(a);
      } else if (x0.contains(a)) {  // Xのみにaがある
        int i = is.at(a); assert(i >= 0);
        if (y1.empty()) {
          ok = false;
          break;
        }
        int j = js.at(*y1.begin());
        board.at(i).at(j) = a;
        x0.erase(a); x1.insert(a);
      } else {  // Yのみにaがある
        assert(y0.contains(a));
        int j = js.at(a); assert(j >= 0);
        if (x1.empty()) {
          ok = false;
          break;
        }
        int i = is.at(*x1.begin()); assert(i >= 0);
        board.at(i).at(j) = a;
        y0.erase(a); y1.insert(a);
      }
      if (!ok) break;
    }
    if (!ok) {
      cout << "No" << '\n';
      continue;
    }
    // st以外はシミュる
    multiset<tuple<int, int, int> , greater<tuple<int, int, int> > > ms;  // まだうまっていない所が入れて良い数の最大値
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (board.at(i).at(j) == -1) {
          int k = min(X.at(i), Y.at(j));
          ms.insert(make_tuple(k, i, j));
        }
      }
    }
    bool ans = true;
    for (int value = N * M; value >= 1; value--) {
      if (st.contains(value)) {
        continue;
      }
      // まだ埋めていない数
      assert(!ms.empty());
      auto [k, i, j] = *ms.begin();
      if (value <= k) {
        ms.erase(ms.begin());
        board.at(i).at(j) = value;
      } else {
        ans = false;
        break;
      }
    }
    cout << (ans ? "Yes" : "No") << '\n';
    if (ans) {
      for (int i = 0; i < N; i++) {
        dump(board.at(i));
      }
    }
  }
  return 0;
}
