#include <iostream>
#include <vector>
using namespace std;

vector<int> X;
vector<vector<int> > graph;
vector<vector<int> > dp;
vector<bool> visited;
void dfs(int u, int parent) {
  visited[u] = true;
  vector<int> ans(20, 0);
  ans[0] = X[u];
  for (size_t i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (v == parent) {
      continue;
    }
    dfs(v, u);
    // merge dp[u] and dp[v]
    int ui = 0;
    int vi = 0;
    vector<int> merged(20, 0);
    for (int k = 0; k < 20; k++) {
      if (ans[ui] >= dp[v][vi]) {
        merged[k] = ans[ui];
        ui++;
      } else {
        merged[k] = dp[v][vi];
        vi++;
      }
    }
    for (int k = 0; k < 20; k++) {
      ans[k] = merged[k];
    }
  }
  for (int k = 0; k < 20; k++) {
    dp[u][k] = ans[k];
  }
  return;
}

int main() {
  int N, Q;
  cin >> N >> Q;
  X.resize(N);
  for (int n = 0; n < N; n++) {
    cin >> X.at(n);
  }
  graph.resize(N);
  for (int n = 0; n < N - 1; n++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
  }
  dp.resize(N, vector<int>(20, 0));
  visited.resize(N, false);
  dfs(0, -1);
  for (int q = 0; q < Q; q++) {
    int V, K;
    cin >> V >> K;
    cout << dp[V - 1][K - 1] << endl;
  }
  return 0;
}
