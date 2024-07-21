// https://www.youtube.com/watch?v=5pxjBcAn3mQ&t=6093s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// 木でstartからの距離を求める。計算量O(N)
vector<long long> calc_dists_tree(const vector<vector<pair<int, long long> > > &graph, int start) {
  int N = graph.size();
  vector<long long> dp(N, 0);  // dp[u]: 始点からuまでの距離
  auto dfs_tree = [&](auto dfs_tree, int u, int parent) -> void {
    for (auto [v, cost] : graph.at(u)) {
      if (v == parent) {
        continue;
      }
      dp.at(v) = dp.at(u) + cost;
      dfs_tree(dfs_tree, v, u);
    }
  };
  dfs_tree(dfs_tree, start, -1);
  return dp;
}

// Diameter of weighted tree
// Augments
//   graph: tree, 0-indexed
long long diameter_tree(const vector<vector<pair<int, long long> > > &graph) {
  // 直径の端点の一つaを求める
  vector<long long> dist0 = calc_dists_tree(graph, 0);
  vector<long long>::iterator it0 = max_element(dist0.begin(), dist0.end());
  int a = it0 - dist0.begin();
  // もう一方の端点bを求める
  vector<long long> dista = calc_dists_tree(graph, a);
  // 直径を返す
  return *max_element(dista.begin(), dista.end());
}

int main() {
  int N;
  cin >> N;
  int M = N - 1;
  vector<vector<pair<int, long long> > > graph(N);
  long long ans = 0;
  for (int m = 0; m < M; m++) {
    int A, B;
    long long C;
    cin >> A >> B >> C;
    A--; B--;
    graph[A].push_back(make_pair(B, C));
    graph[B].push_back(make_pair(A, C));
    ans += C * 2;
  }
  ans -= diameter_tree(graph);
  cout << ans << endl;
  return 0;
}
