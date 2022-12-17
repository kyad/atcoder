#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#include <atcoder/scc>
using namespace atcoder;

vector<int> color;
bool dfs(const vector<vector<int> > &graph, int v, int cur = 0) {
  color[v] = cur;
  for (size_t i = 0; i < graph[v].size(); i++) {
    int next_v = graph[v][i];
    if (color[next_v] != -1) {
      if (color[next_v] == cur) {
        return false;
      }
      continue;
    }
    if (!dfs(graph, next_v, 1 - cur)) {
      return false;
    }
  }
  return true;
}

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
  color.assign(N, -1);
  bool is_bipartite = true;
  for (int v = 0; v < N; v++) {
    if (color[v] != -1) {
      continue;
    }
    if (!dfs(graph, v)) {
      is_bipartite = false;
    }
  }

  if (!is_bipartite) {
    cout << 0 << endl;
    return 0;
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
      long long a = (long long)us1.size() - (long long)graph[u].size();
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
