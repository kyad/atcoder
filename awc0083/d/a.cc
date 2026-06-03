#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<string> S(H, string(W, '.'));
  for (int i = 0; i < N; i++) {
    int R, C;
    cin >> R >> C;
    R--;
    C--;
    S.at(R).at(C) = '#';
  }
  int M = H * W;
  auto encode = [&](int y, int x) { return y * W + x; };
  auto decode = [&](int z) -> pair<int, int> {
    int y = z / W;
    int x = z % W;
    return make_pair(y, x);
  };
  vector<vector<int>> graph(M);
  const int dy[4] = {0, -1, 0, +1};
  const int dx[4] = {+1, 0, -1, 0};
  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      for (int k = 0; k < 4; k++) {
        int y = r;
        int x = c;
        int z = encode(y, x);
        while (true) {
          int ny = y + dy[k];
          int nx = x + dx[k];
          if (0 <= ny && ny < H && 0 <= nx && nx < W && S.at(ny).at(nx) == '.') {
            y = ny;
            x = nx;
          } else {
            break;
          }
        }
        int nz = encode(y, x);
        graph.at(z).push_back(nz);
      }
    }
  }
  // BFS
  int s = encode(0, 0);  // 探索開始ノード
  queue<int> todo;
  vector<int> dist(M, -1);
  dist.at(s) = 0;
  todo.push(s);
  while (!todo.empty()) {
    int u = todo.front();
    todo.pop();
    for (int v : graph.at(u)) {
      if (dist.at(v) < 0) {
        dist.at(v) = dist.at(u) + 1;
        todo.push(v);
      }
      // if (dist.at(v) == dist.at(u) + 1) {  // 前に、uと同じ距離のノードからvに訪れていた場合の処理
      // }
    }
  }
  int end = encode(H - 1, W - 1);
  int ans = dist.at(end);
  cout << ans << '\n';
  return 0;
}
