// https://atcoder.jp/contests/abc292/tasks/abc292_e
// Loop detection is not validated

#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

long long solve(const vector<vector<int> > &graph, int s) {
  int N = graph.size();
  vector<bool> visited(N, false);
  vector<int> loop(N, 0);
  auto dfs = [&](auto dfs, int u, int parent) -> void {
    visited[u] = true;
    for (int v : graph[u]) {
      if (v == parent) {
        continue;
      }
      if (visited[v]) {
        loop[v] = 1;
      } else {
        dfs(dfs, v, u);
      }
      if (loop[v] == 1) {
        loop[v] = 2;
      }
    }
  };
  dfs(dfs, s, -1);
  long long ans = 0;
  set<int> st;
  for (int u : graph[s]) {
    st.insert(u);
  }
  for (int u = 0; u < N; u++) {
    if (u == s) {
      continue;
    } else {
      if (visited[u] && st.count(u) == 0) {
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph(N);
  for (int m = 0; m < M; m++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    graph[u].push_back(v);
  }

  long long ans = 0;
  for (int u = 0; u < N; u++) {
    ans += solve(graph, u);
  }
  cout << ans << endl;
  return 0;
}
