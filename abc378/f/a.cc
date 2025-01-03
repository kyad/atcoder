#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long comb2(long long N) { return N * (N - 1) / 2; }

int main() {
  int N;
  cin >> N;
  vector<vector<int> > graph(N);
  vector<int> deg(N, 0);
  for (int m = 0; m < N - 1; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph[U].push_back(V);
    graph[V].push_back(U);
    deg.at(U)++;
    deg.at(V)++;
  }

  // deg=3のノードののみ有効。-1は未訪問。>=0の場合、子のdeg=2の個数
  vector<int> child(N, -1);
  // 木DP。計算量O(N)。graphは有向でも無向でも良い
  auto dfs_tree = [&](auto dfs_tree, int u, int parent) -> int {
    // uに最初に訪問した
    if (deg.at(u) != 3) {  // degが3以外なら終了
      if (deg.at(u) == 2) {
        return 1;
      } else {
        return 0;
      }
    }
    // degが3なら訪問済みにして探索を続ける
    // uの初期化
    child[u] = 0;  // u以下のdeg=2のノードの個数(u含む)
    for (int v : graph.at(u)) {
      if (v == parent) {
        continue;
      }
      // 行きがけ u --> v
      int now = dfs_tree(dfs_tree, v, u);
      // 帰りがけ u <-- v
      child.at(u) += now;
    }
    return child.at(u);
  };

  long long ans = 0;

  for (int u = 0; u < N; u++) {
    if (deg.at(u) == 3 && child.at(u) == -1) { // 未訪問の場合のみ
      long long num = dfs_tree(dfs_tree, u, -1);
      long long now = comb2(num);
      ans += now;
    }
  }

  cout << ans << endl;
  return 0;
}
