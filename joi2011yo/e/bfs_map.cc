// https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<string> board(H);
  vector<int> sy(N + 1, -1);
  vector<int> sx(N + 1, -1);
  for (int y = 0; y < H; y++) {
    cin >> board.at(y);
    for (int x = 0; x < W; x++) {
      char c = board[y][x];
      if (c == 'S') {
        sy[0] = y;
        sx[0] = x;
      } else if ('0' < c && c <= '9') {
        sy[c - '0'] = y;
        sx[c - '0'] = x;
      }
    }
  }
  int ans = 0;
  for (int n = 0; n < N; n++) {
    vector<vector<int> > dist(H, vector<int>(W, -1));
    queue<pair<int, int> > todo;
    todo.push(make_pair(sy.at(n), sx.at(n)));
    dist[sy.at(n)][sx.at(n)] = 0;
    while (!todo.empty()) {
      int y = todo.front().first;
      int x = todo.front().second;
      todo.pop();
      const int dy[4] = {-1, 0, 1, 0};
      const int dx[4] = {0, -1, 0, 1};
      for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
          continue;
        }
        if (dist[ny][nx] >= 0) {
          continue;
        }
        if (board[ny][nx] == 'X') {
          continue;
        }
        todo.push(make_pair(ny, nx));
        dist[ny][nx] = dist[y][x] + 1;
      }
    }
    ans += dist[sy.at(n + 1)][sx.at(n + 1)];
  }
  cout << ans << endl;
  return 0;
}
