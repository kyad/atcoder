// https://atcoder.jp/contests/abc226/tasks/abc226_e

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > graph;
vector<bool> seen;
vector<int> nodes;

void dfs(int u) {
  seen[u] = true;
  nodes.push_back(u);
  for (size_t i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (seen[v]) {
      continue;
    }
    dfs(v);
  }
}

int main() {
  const int MOD = 998244353;
  int N, M;
  cin >> N >> M;
  graph.resize(N);
  for (int m = 0; m < M; m++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  seen.assign(N, false);
  long long ans = 1;
  for (int n = 0; n < N; n++) {
    if (seen[n]) {
      continue;
    }
    nodes.clear();
    dfs(n);
    size_t edges = 0;
    for (size_t i = 0; i < nodes.size(); i++) {
      edges += graph[nodes[i]].size();
    }
    edges /= 2;
    if (nodes.size() == edges) {
      ans *= 2;
      ans %= MOD;
    } else {
      ans = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
