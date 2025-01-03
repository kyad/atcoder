#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int y = 0; y < N; y++) {
    cin >> S.at(y);
  }
  vector<int> sy(2);
  vector<int> sx(2);
  int idx = 0;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (S.at(y).at(x) == 'P') {
        sy.at(idx) = y;
        sx.at(idx) = x;
        idx++;
      }
    }
  }
  assert(idx == 2);
  auto encode = [&](int y, int x) { return y * N + x; };
  auto decode = [&](int z) -> pair<int, int> {
    int y = z / N;
    int x = z % N;
    return make_pair(y, x);
  };
  vector<int> sz(2);
  for (int i = 0; i < 2; i++) sz.at(i) = encode(sy.at(i), sx.at(i));
  // BFS
  pair<int, int> s = make_pair(sz.at(0), sz.at(1));  // 探索開始ノード
  queue<pair<int, int> > todo;
  vector<vector<int> > dist(N * N, vector<int>(N * N, -1));  // dist[z0][z1]: 状態z0, z1の距離
  dist.at(sz.at(0)).at(sz.at(1)) = 0;
  todo.push(s);
  const int dy[4] = {0, -1, 0, +1};
  const int dx[4] = {+1, 0, -1, 0};
  while (!todo.empty()) {
    auto [z0, z1] = todo.front();
    auto [y0, x0] = decode(z0);
    auto [y1, x1] = decode(z1);
    todo.pop();
    // 遷移
    int ndist = dist.at(z0).at(z1) + 1;
    for (int k = 0; k < 4; k++) {
      vector<int> y(2), x(2), z(2);
      y.at(0) = y0; x.at(0) = x0;
      y.at(1) = y1; x.at(1) = x1;
      // プレイヤー1, 2を1個進める
      for (int i = 0; i < 2; i++) {
        int ny = y.at(i) + dy[k];
        int nx = x.at(i) + dx[k];
        if (ny >= 0 && ny < N && nx >= 0 && nx < N && S.at(ny).at(nx) != '#') {
          y.at(i) = ny;
          x.at(i) = nx;
        }
        z.at(i) = encode(y.at(i), x.at(i));
      }
      if (z.at(0) == z.at(1)) {  // 一致
        cout << ndist << endl;
        return 0;
      }
      if (dist.at(z.at(0)).at(z.at(1)) < 0) {
        dist.at(z.at(0)).at(z.at(1)) = ndist;
        todo.push(make_pair(z.at(0), z.at(1)));
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
