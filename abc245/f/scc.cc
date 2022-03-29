// https://atcoder.jp/contests/abc245/tasks/abc245_f
// https://atcoder.github.io/ac-library/production/document_ja/scc.html
// 強連結成分分解

#include <iostream>
#include <atcoder/scc>

using namespace std;
using namespace atcoder;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > G(N);
  scc_graph graph(N);
  for (int m = 0; m < M; m++) {
    int U, V;
    cin >> U >> V;
    U--;
    V--;
    G.at(U).push_back(V);
    graph.add_edge(U, V);
  }
  vector<vector<int> > scc = graph.scc();
  int K = scc.size();
  vector<int> node_to_scc(N, -1);
  for (int k = 0; k < K; k++) {
    for (size_t i = 0; i < scc.at(k).size(); i++) {
      node_to_scc[scc.at(k).at(i)] = k;
    }
  }
  vector<bool> dp(K, false);
  for (int k = K - 1; k >= 0; k--) {
    if (scc[k].size() >= 2) {
      dp[k] = true;
      continue;
    }
    int u = scc[k][0];
    for (size_t i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (dp[node_to_scc[v]]) {
        dp[k] = true;
      }
    }
  }
  int ans = 0;
  for (int k = 0; k < K; k++) {
    if (dp[k]) {
      ans += scc[k].size();
    }
  }
  cout << ans << endl;
  return 0;
}
