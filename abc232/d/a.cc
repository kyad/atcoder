#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> C(H);
  for (int y = 0; y < H; y++) {
    cin >> C.at(y);
  }
  // BFS
  queue<pair<int, int> > todo;
  vector<vector<int> > dist(H, vector<int>(W, -1));
  todo.push(make_pair(0, 0));
  dist[0][0] = 1;
  while (!todo.empty()) {
    int y = todo.front().first;
    int x = todo.front().second;
    todo.pop();
    const int dy[2] = {1, 0};
    const int dx[2] = {0, 1};
    for (int k = 0; k < 2; k++) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
        continue;
      }
      if (C[ny][nx] == '#') {
        continue;
      }
      if (dist[ny][nx] >= 0) {
        continue;
      }
      dist[ny][nx] = dist[y][x] + 1;
      todo.push(make_pair(ny, nx));
    }
  }
  int ans = 0;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (dist[y][x] < 0) {
        continue;
      }
      ans = max(ans, dist[y][x]);
    }
  }
  cout << ans << endl;
  return 0;
}
