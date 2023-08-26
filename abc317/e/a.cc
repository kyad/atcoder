#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  for (int y = 0; y < H; y++) {
    cin >> A.at(y);
  }
  // トレーナーがいるマスを探索
  const int dy[4] = { 0, -1,  0, +1};
  const int dx[4] = {+1,  0, -1,  0};
  int sy = -1;
  int sx = -1;
  int gy = -1;
  int gx = -1;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      int k = -1;
      if (A[y][x] == '>') {
        k = 0;
      } else if (A[y][x] == '^') {
        k = 1;
      } else if (A[y][x] == '<') {
        k = 2;
      } else if (A[y][x] == 'v') {
        k = 3;
      } else if (A[y][x] == 'S') {
        sy = y;
        sx = x;
        continue;
      } else if (A[y][x] == 'G') {
        gy = y;
        gx = x;
        continue;
      }
      if (k < 0) {
        continue;
      }
      int yy = y;
      int xx = x;
      while (true) {
        int nyy = yy + dy[k];
        int nxx = xx + dx[k];
        if (nyy < 0 || nyy >= H || nxx < 0 || nxx >= W) {
          break;
        }
        if (A[nyy][nxx] == '>' || A[nyy][nxx] == '^' || A[nyy][nxx] == '<' || A[nyy][nxx] == 'v'
            || A[nyy][nxx] == '#' || A[nyy][nxx] == 'S' || A[nyy][nxx] == 'G') {
          break;
        }
        A[nyy][nxx] = '!';
        yy = nyy;
        xx = nxx;
      }
    }
  }
  // BFS
  queue<pair<int, int> > todo;
  vector<vector<int> > dist(H, vector<int>(W, -1));
  dist.at(sy).at(sx) = 0;
  todo.push(make_pair(sy, sx));
  while (!todo.empty()) {
    auto [y, x] = todo.front();
    todo.pop();
    for (int k = 0; k < 4; k++) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
        continue;
      }
      if (A[ny][nx] == '>' || A[ny][nx] == '^' || A[ny][nx] == '<' || A[ny][nx] == 'v'
          || A[ny][nx] == '#' || A[ny][nx] == '!') {
        continue;
      }
      if (dist.at(ny).at(nx) < 0) {
        dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
        todo.push(make_pair(ny, nx));
      }
    }
  }
  cout << dist.at(gy).at(gx) << endl;
  return 0;
}
