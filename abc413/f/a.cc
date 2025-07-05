#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

const long long INF = 4e18;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<long long> > dist(H, vector<long long>(W, INF));
  queue<tuple<long long, int, int>> pq;
  int dy[4] = {-1, +1,  0,  0};
  int dx[4] = { 0,  0, -1, +1};
  for (int k = 0; k < K; k++) {
    int Y, X;
    cin >> Y >> X;
    Y--; X--;
    dist.at(Y).at(X) = 0;
    pq.push(make_tuple(0, Y, X));
  }
  while (!pq.empty()) {
    auto [d, y, x] = pq.front();
    pq.pop();
    if (d > dist.at(y).at(x)) {
      continue;  // Garbage
    }
    for (int k = 3; k >= 0; k--) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (ny < 0 || nx < 0 || ny >= H || nx >= W) {
        continue;
      }
      vector<long long> ds;  // (ny, nx)に隣接するマスの距離
      for (int l = 3; l >= 0; l--) {
        int Y = ny + dy[l];
        int X = nx + dx[l];
        if (Y < 0 || X < 0 || Y >= H || X >= W || dist.at(Y).at(X) == INF) {
          continue;
        }
        ds.push_back(dist.at(Y).at(X));
      }
      if (ds.size() >= 2) {
        sort(ds.begin(), ds.end());
        long long now = ds.at(1) + 1;
        if (now < dist.at(ny).at(nx)) {
          dist.at(ny).at(nx) = now;
          pq.push(make_tuple(now, ny, nx));
        }
      }
    }
  }
  long long ans = 0;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (dist.at(y).at(x) < INF) {
        ans += dist.at(y).at(x);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
