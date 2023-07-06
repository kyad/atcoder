#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> C(H);
  for (int y = 0; y < H; y++) {
    cin >> C.at(y);
  }
  int N = H * W;
  const int dy[4] = {0, -1, 0, 1};
  const int dx[4] = {-1, 0, 1, 0};

  auto decode = [&](int u) -> pair<int, int> {
    int x = u % W;
    int y = u / W;
    return make_pair(y, x);
  };
  auto encode = [&](int y, int x) {
    return y * W + x;
  };

  // graph[u]: uから行けるノード番号
  vector<vector<int> > graph(N);
  for (int u = 0; u < N; u++) {
    auto [y, x] = decode(u);
    if (C[y][x] == '#') {
      continue;
    }
    for (int k = 0; k < 4; k++) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
        continue;
      }
      if (C[ny][nx] == '#') {
        continue;
      }
      int nu = encode(ny, nx);
      graph[u].push_back(nu);
    }
  }

  int ans = -1;
  for (int s = 0; s < N; s++) {
    vector<bool> visited(N, false);
    // 木DP。計算量O(N)。graphは有向でも無向でも良い
    auto dfs_tree = [&](auto dfs_tree, int u, int parent, int len) -> void {
      // 終了条件
      if (u == s && len > 0) {
        if (len >= 3) {
          ans = max(ans, len);
        }
        return;
      }
      for (int v : graph.at(u)) {
        if (v == parent) {
          continue;
        }
        if (visited[v]) {
          continue;
        }
        // 行きがけ u --> v
        visited[v] = true;
        dfs_tree(dfs_tree, v, u, len + 1);
        // 帰りがけ u <-- v
        visited[v] = false;
      }
    };
    dfs_tree(dfs_tree, s, -1, 0);
  }
  cout << ans << endl;
  return 0;
}
