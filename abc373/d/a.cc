#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, long long> > > graph(N);
  for (int j = 0; j < M; j++) {
    int U, V, W;
    cin >> U >> V >> W;
    U--; V--;
    graph[U].push_back(make_pair(V, W));
    graph[V].push_back(make_pair(U, -W));
  }
  
  vector<bool> seen(N, false);  // 探索完了フラグ
  vector<long long> X(N, 0);
  auto dfs = [&](auto dfs, int u) -> void {
    seen.at(u) = true;  // 訪問済(訪問完了)
    // if () {
    //   return;
    // }
    for (auto [v, w] : graph.at(u)) {
      if (seen.at(v)) {
        continue;
      }
      X.at(v) = X.at(u) + w;
      dfs(dfs, v);
    }
  };

  for (int u = 0; u < N; u++) {
    if (!seen[u]) {
      dfs(dfs, u);
    }
  }

  dump(X);
  return 0;
}
