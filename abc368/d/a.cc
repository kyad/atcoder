#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<vector<int> > graph(N);
  for (int m = 0; m < N - 1; m++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }
  vector<bool> count(N, false);
  vector<int> V(K);
  for (int k = 0; k < K; k++) {
    cin >> V.at(k);
    V.at(k)--;
    count.at(V.at(k)) = true;
  }

  // 木DP。計算量O(N)。graphは有向でも無向でも良い
  auto dfs_tree = [&](auto dfs_tree, int u, int parent) -> void {
    // uに最初に訪問した
    // uの初期化
    for (int v : graph.at(u)) {
      if (v == parent) {
        continue;
      }
      // 行きがけ u --> v
      dfs_tree(dfs_tree, v, u);
      if (count.at(v)) {
        count.at(u) = true;
      }
      // 帰りがけ u <-- v
      // uの更新
    }
  };
  dfs_tree(dfs_tree, V.at(0), -1);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (count.at(i)) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
