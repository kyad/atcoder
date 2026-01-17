#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
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
  int N, M, L;
  cin >> N >> M >> L;
  long long S, T;
  cin >> S >> T;
  vector<vector<pair<int, long long> > > graph(N);
  for (int j = 0; j < M; j++) {
    int U, V;
    long long C;
    cin >> U >> V >> C;
    U--; V--;
    graph.at(U).push_back(make_pair(V, C));
  }
  // 点、通った数、総和
  queue<tuple<int, int, long long> > q;
  q.push(make_tuple(0, 0, 0));
  vector<bool> ok(N, false);
  while (!q.empty()) {
    auto [u, l, cost] = q.front();
    // チェック
    if (l == L && S <= cost && cost <= T) {
      ok.at(u) = true;
    }
    q.pop();
    for (auto [v, c]: graph.at(u)) {
      if (l + 1 <= L && cost + c <= T) {
        q.push(make_tuple(v, l + 1, cost + c));
      }
    }
  }
  vector<int> ans;
  for (int u = 0; u < N; u++) {
    if (ok.at(u)) {
      ans.push_back(u + 1);
    }
  }
  dump(ans);
  return 0;
}
