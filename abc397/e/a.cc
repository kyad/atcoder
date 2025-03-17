// https://atcoder.jp/contests/abc397/editorial/12452

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<vector<int> > graph(N * K);
  for (int m = 0; m < N * K - 1; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph.at(U).push_back(V);
    graph.at(V).push_back(U);
  }

  vector<int> dp(N * K, 0);  // 自分より下のレンの長さ。丁度Kになった時は0にする
  // 木DP。計算量O(N)。graphは有向でも無向でも良い
  auto dfs_tree = [&](auto dfs_tree, int u, int parent) -> void {
    int count = 0;  // 子の中でdpが1以上の個数
    dp.at(u) = 1;  // 子のdpの合計
    for (int v : graph.at(u)) {
      if (v == parent) {
        continue;
      }
      // 行きがけ u --> v
      dfs_tree(dfs_tree, v, u);
      if (dp.at(v) >= 1) {
        count++;
      }
      dp.at(u) += dp.at(v);
    }
    if (dp.at(u) < K) {
      if (count >= 2) {
        cout << "No" << endl;
        exit(0);
      }
    } else if (dp.at(u) == K) {
      if (count >= 3) {
        cout << "No" << endl;
        exit(0);
      }
      dp.at(u) = 0;
    } else if (dp.at(u) > K) {
      cout << "No" << endl;
      exit(0);
    }
  };
  dfs_tree(dfs_tree, 0, -1);
  cout << "Yes" << endl;
  return 0;
}
