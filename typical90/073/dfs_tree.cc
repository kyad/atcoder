// https://twitter.com/e869120/status/1407510677934149635
// https://github.com/E869120/kyopro_educational_90/blob/main/sol/073.cpp

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
// modint
#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}


int main() {
  int N;
  cin >> N;
  vector<char> color(N);
  for (int n = 0; n < N; n++) {
    cin >> color.at(n);
  }
  vector<vector<int> > graph(N);
  for (int m = 0; m < N - 1; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph[U].push_back(V);
    graph[V].push_back(U);
  }

  // dp[u][j]: uから下の求める個数。
  // uの連結成分がj=0:aのみ、j=1:bのみ、j=2:aとb
  vector<vector<mint> > dp(N, vector<mint>(3, 0));

  // 木DP。計算量O(N)。graphは有向でも無向でも良い
  auto dfs_tree = [&](auto dfs_tree, int u, int parent) -> void {
    // uに最初に訪問した
    // uの初期化
    int k = color[u] == 'a' ? 0 : 1;
    dp[u][k] = 1;
    mint all = 1;
    for (int v : graph.at(u)) {
      if (v == parent) {
        continue;
      }
      // 行きがけ u --> v
      dfs_tree(dfs_tree, v, u);
      // 帰りがけ u <-- v
      // uの更新
      dp[u][k] *= (dp[v][k] + dp[v][2]);
      all *= (dp[v][0] + dp[v][1] + dp[v][2] * 2);
    }
    dp[u][2] = all - dp[u][k];
  };
  dfs_tree(dfs_tree, 0, -1);
  cout << dp[0][2] << endl;
  return 0;
}
