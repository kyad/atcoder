#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#include <atcoder/scc>
using namespace atcoder;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph(N);
  scc_graph scc_g(N);
  for (int m = 0; m < M; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph[U].push_back(V);
    graph[V].push_back(U);
    scc_g.add_edge(U, V);
    scc_g.add_edge(V, U);
  }
  // DFS
  vector<int> color(N, -1);
  vector<bool> seen(N, false);

  auto dfs = [&](auto dfs, int u, int c) -> bool {
    seen[u] = true;  // 訪問済(訪問完了)
    assert(c == 0 || c == 1);
    color[u] = c;  // 訪問済のタイミングで色確定
    int nc = 1 - c;
    for (size_t i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i];
      if (seen[v]) {
        if (color[v] >= 0 && color[v] != nc) {
          // not biparete
          return false;
        }
        continue;
      }
      if (!dfs(dfs, v, nc)) {
        return false;
      }
    }
    return true;
  };

  for (int u = 0; u < N; u++) {
    if (seen[u]) {
      continue;
    }
    bool now = dfs(dfs, u, 0);
    if (!now) {
      cout << 0 << endl;
      return 0;
    }
  }

  vector<vector<int> > scc = scc_g.scc();
  long long ans = 0;
  long long res = N;

  for (size_t i = 0; i < scc.size(); i++) {
    // u内の連結成分
    vector<int> us0, us1;
    for (int u : scc[i]) {
      assert(color[u] == 0 || color[u] == 1);
      if (color[u] == 0) {
        us0.push_back(u);
      } else {
        us1.push_back(u);
      }
    }
    long long now = 0;
    for (int u : us0) {
      int a = (int)us1.size() - (int)graph[u].size();
      assert(a >= 0);
      now += a;
    }
    ans += now;

    // 連結成分の間
    {
      long long sz = scc[i].size();
      res -= sz;
      long long now = sz * res;
      ans += now;
    }
  }
  cout << ans << endl;
  return 0;
}
