#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, const T b) { a = max(a, b); }

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph(N);
  for (int n = 1; n < N; n++) {
    int P;
    cin >> P;
    P--;
    graph[P].push_back(n);
  }
  vector<int> dp(N, 0);
  for (int m = 0; m < M; m++) {
    int X, Y;
    cin >> X >> Y;
    X--;
    chmax(dp[X], Y + 1);
  }
  // 木DP。計算量O(N)。graphは有向でも無向でも良い
  auto dfs_tree = [&](auto dfs_tree, int u, int parent) -> void {
    // uに最初に訪問した
    // uの初期化
    // child[u] = 1;  // u以下のノードの個数(u含む)
    for (int v : graph.at(u)) {
      if (v == parent) {
        continue;
      }
      // 行きがけ u --> v
      if (dp[u] >= 1) {
        chmax(dp[v], dp[u] - 1);
      }
      dfs_tree(dfs_tree, v, u);
      // 帰りがけ u <-- v
      // uの更新
      // child[u] += child[v];
    }
  };
  dfs_tree(dfs_tree, 0, -1);
  int ans = 0;
  for (int u = 0; u < N; u++) {
    if (dp[u] >= 1) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
