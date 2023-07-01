#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  auto f = [](char c) {
    if (c == 's') { return 0; }
    else if (c == 'n') { return 1; }
    else if (c == 'u') { return 2; }
    else if (c == 'k') { return 3; }
    else if (c == 'e') { return 4; }
    return -1;
  };
  // BFS
  int sy = 0;
  int sx = 0;  // 探索開始ノード
  queue<pair<int, int> > todo;
  vector<vector<int> > dist(H, vector<int>(W, -1));
  if (f(S[sy][sx]) >= 0) {
    dist.at(sy).at(sx) = 0;
    todo.push(make_pair(sy, sx));
  }
  const int dy[4] = {0, 1, 0, -1};
  const int dx[4] = {-1, 0, 1, 0};
  while (!todo.empty()) {
    pair<int, int> u = todo.front();
    int y = u.first;
    int x = u.second;
    char c = f(S[y][x]);
    assert(c >= 0);
    todo.pop();
    for (int k = 0; k < 4; k++) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
        continue;
      }
      int nc = f(S[ny][nx]);
      if (nc < 0) {
        continue;
      }
      if ((c + 1) % 5 != nc) {
        continue;
      }
      if (dist.at(ny).at(nx) < 0) {
        dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
        todo.push(make_pair(ny, nx));
      }
      // if (dist.at(v) == dist.at(u) + 1) {  // 前に、uと同じ距離のノードからvに訪れていた場合の処理
      // }
    }
  }
  bool ans = dist[H - 1][W - 1] >= 0;
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
