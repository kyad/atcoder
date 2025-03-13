#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, long long> > > graph(N);
  for (int i = 0; i < M; i++) {
    int U, V;
    long long W;
    cin >> U >> V >> W;
    U--; V--;
    graph.at(U).push_back(make_pair(V, W));
    graph.at(V).push_back(make_pair(U, W));
  }
  long long ans = 1LL<<60;
  long long weight = 0;
  vector<bool> visited(N, false);
  auto dfs = [&](auto dfs, int u) -> void {
    if (u == N - 1) {
      ans = min(ans, weight);
      return;
    }
    visited.at(u) = true;
    for (auto [v, w] : graph.at(u)) {
      if (visited.at(v)) {
        continue;
      }
      weight ^= w;
      dfs(dfs, v);
      weight ^= w;
    }
    visited.at(u) = false;
  };
  dfs(dfs, 0);
  cout << ans << endl;
  return 0;
}
