#include <iostream>
#include <vector>
using namespace std;

const int INF = 300000;
int leaf;
vector<vector<int> > graph;
vector<int> dp_l;
vector<int> dp_r;
void dfs(int u, int parent) {
  dp_l[u] = INF;
  dp_r[u] = 0;
  for (size_t i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (v == parent) {
      continue;
    }
    dfs(v, u);
    dp_l[u] = min(dp_l[u], dp_l[v]);
    dp_r[u] = max(dp_r[u], dp_r[v]);
  }
  if (dp_l[u] == INF && dp_r[u] == 0) { // leaf
    leaf++;
    dp_l[u] = leaf;
    dp_r[u] = leaf;
  }
  return;
}

int main() {
  int N;
  cin >> N;
  graph.resize(N);
  for (int n = 0; n < N - 1; n++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    graph.at(u).push_back(v);
    graph.at(v).push_back(u);
  }
  leaf = 0;
  dp_l.resize(N, 0);
  dp_r.resize(N, 0);
  dfs(0, -1);
  for (int n = 0; n < N; n++) {
    cout << dp_l[n] << ' ' << dp_r[n] << endl;
  }
  return 0;
}
