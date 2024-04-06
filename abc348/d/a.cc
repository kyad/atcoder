// https://atcoder.jp/contests/abc348/editorial/9705

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
  int sy = -1;
  int sx = -1;
  int ty = -1;
  int tx = -1;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (A[y][x] == 'S') {
        sy = y;
        sx = x;
      } else if (A[y][x] == 'T') {
        ty = y;
        tx = x;
      }
    }
  }
  assert(sy >= 0 && sx >= 0 && ty >= 0 && tx >= 0);
  vector<vector<int> > E(H, vector<int>(W, 0));
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int r, c, e;
    cin >> r >> c >> e;
    r--; c--;
    E.at(r).at(c) = e;
  }

  // BFS
  using T = pair<int, int>;
  T s = make_pair(sy, sx);  // 探索開始ノード
  queue<T> todo;
  // dp[y][x]: (y, x)に到達した時の最大エネルギー。-1は到達していない。
  vector<vector<int> > dp(H, vector<int>(W, -1));
  dp[sy][sx] = 0;
  todo.push(s);
  while (!todo.empty()) {
    T u = todo.front();
    todo.pop();
    int y = get<0>(u);
    int x = get<1>(u);
    // もし薬が置いてあれば
    if (E[y][x] > 0) {
      dp[y][x] = max(dp[y][x], E[y][x]);
    }
    // 隣りも移動可能とする処理
    const int dy[4] = {1, 0, -1, 0};
    const int dx[4] = {0, 1, 0, -1};
    for (int k = 0; k < 4; k++) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W || A[ny][nx] == '#') {
        continue;
      }
      int ndp = dp[y][x] - 1;
      if (ndp < 0) {
        continue;
      }
      if (dp[ny][nx] < ndp) {
        dp[ny][nx] = ndp;
        todo.push(make_pair(ny, nx));
      }
    }
  }

  bool ans = dp[ty][tx] >= 0;
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
