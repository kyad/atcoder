#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > graph(N);
  for (int n = 0; n < N - 1; n++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph[U].push_back(V);
    graph[V].push_back(U);
  }
  // 木DP。計算量O(N)。graphは有向でも無向でも良い
  vector<int> child(N, 0);
  auto dfs_tree = [&](auto dfs_tree, int u, int parent) -> void {
    // uに最初に訪問した
    // uの初期化
    child[u] = 1;  // u以下のノードの個数(u含む)
    for (int v : graph.at(u)) {
      if (v == parent) {
        continue;
      }
      // 行きがけ u --> v
      dfs_tree(dfs_tree, v, u);
      // 帰りがけ u <-- v
      // uの更新
      child[u] += child[v];
    }
  };
  int root = 0;
  dfs_tree(dfs_tree, root, -1);
  long long sum = 0;
  const long long INF = 4e18;
  long long mx = -INF;
  for (int u : graph[0]) {
    long long now = child[u];
    sum += now;
    mx = max(mx, now);
  }
  long long ans = sum - mx + 1;
  cout << ans << endl;
  return 0;
}
