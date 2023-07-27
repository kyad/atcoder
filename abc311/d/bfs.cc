#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int y = 0; y < N; y++) {
    cin >> S.at(y);
  }
  // BFS
  queue<tuple<int, int, int> > todo;
  vector<vector<vector<int> > > dist(N, vector<vector<int> > (M, vector<int>(4, -1)));
  const int dy[4] = {1, 0, -1, 0};
  const int dx[4] = {0, 1, 0, -1};
  for (int k = 0; k < 4; k++) {
    dist.at(1).at(1).at(k) = 0;
    todo.push(make_tuple(1, 1, k));
  }
  while (!todo.empty()) {
    int y = get<0>(todo.front());
    int x = get<1>(todo.front());
    int k = get<2>(todo.front());
    todo.pop();
    int ny = y + dy[k];
    int nx = x + dx[k];
    if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
      continue;
    }
    if (S[ny][nx] == '.') {
      if (dist.at(ny).at(nx).at(k) < 0) {
        dist.at(ny).at(nx).at(k) = dist.at(y).at(x).at(k) + 1;
        todo.push(make_tuple(ny, nx, k));
      }
    } else {  // "#"
      for (int nk = 0; nk < 4; nk++) {
        if (k == nk) {
          continue;
        }
        if (dist[y][x][nk] < 0) {
          assert(dist[y][x][k] >= 0);
          dist[y][x][nk] = dist[y][x][k];
          todo.push(make_tuple(y, x, nk));
        }
      }
    }
  }
  long long ans = 0;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      int now = 0;
      for (int k = 0; k < 4; k++) {
        if (dist[y][x][k] >= 0) {
          now = 1;
        }
      }
      ans += now;
    }
  }
  cout << ans << endl;
  return 0;
}
