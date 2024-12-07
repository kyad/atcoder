#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int H, W, D;
  cin >> H >> W >> D;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }

  // BFS
  const int dy[4] = { 0, -1,  0, +1};
  const int dx[4] = {+1,  0, -1,  0};
  queue<pair<int, int> > todo;
  vector<vector<int> > dist(H, vector<int>(W, -1));
  // 多始点  
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S[y][x] == 'H') {
        dist.at(y).at(x) = 0;
        todo.push(make_pair(y, x));
      }
    }
  }
  while (!todo.empty()) {
    auto [y, x] = todo.front();
    todo.pop();
    for (int k = 0; k < 4; k++) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
        continue;
      }
      // 壁の条件
      if (S[ny][nx] == '#') {
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
      if (dist.at(y).at(x) >= 0 && dist.at(y).at(x) <= D) {
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
