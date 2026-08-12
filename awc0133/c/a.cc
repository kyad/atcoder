#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  K--;
  vector<vector<int> > graph(N);
  for (int j = 1; j < N; j++) {
    int P;
    cin >> P;
    P--;
    graph.at(P).push_back(j);
    graph.at(j).push_back(P);
  }
  vector<bool> dp(N, false);  // 破壊される所がtrue
  auto dfs = [&](auto dfs, int u, int parent, bool hakai) -> void {
    if (u == K) {
      hakai = true;
    }
    if (hakai) {
      dp.at(u) = true;
    }
    for (int v : graph.at(u)) {
      if (v == parent) {
        continue;
      }
      dfs(dfs, v, u, hakai);
    }
  };
  dfs(dfs, 0, -1, false);
  int ans = count(dp.begin(), dp.end(), false);
  cout << ans << '\n';
  return 0;
}
