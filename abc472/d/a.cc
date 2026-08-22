#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  // 安全な空マスを求める
  vector<int> T(H, 0), U(W, 0);
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S.at(y).at(x) == '#') {
        T.at(y)++;
        U.at(x)++;
      }
    }
  }

  // BFS
  queue<pair<int, int>> todo;
  vector<vector<int>> dist(H, vector<int>(W, -1));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (T.at(y) == 0 && U.at(x) == 0 && S.at(y).at(x) == '.') {
        dist.at(y).at(x) = 0;
        todo.push(make_pair(y, x));
      }
    }
  }
  const int dy[4] = {0, -1, 0, +1};
  const int dx[4] = {+1, 0, -1, 0};
  while (!todo.empty()) {
    auto [y, x] = todo.front();
    todo.pop();
    for (int k = 0; k < 4; k++) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W || S.at(ny).at(nx) == '#') {
        continue;
      }
      if (dist.at(ny).at(nx) < 0) {
        dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
        todo.push(make_pair(ny, nx));
      }
    }
  }
  int ans = 0;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (0 <= dist.at(y).at(x) && dist.at(y).at(x) <= K) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
