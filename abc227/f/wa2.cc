// https://atcoder.jp/contests/abc227/tasks/abc227_f

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<int> > A(H, vector<int>(W));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cin >> A[y][x];
    }
  }
  const long long INF = 1000000000LL * (30 + 30) + 1;
  vector<vector<long long> > cost(H, vector<long long>(W, INF));
  vector<vector<multiset<int> > > ms(H, vector<multiset<int> >(W));
  cost[0][0] = A[0][0];
  ms[0][0].insert(A[0][0]);
  for (int k = 0; k < H + W - 2; k++) {  // k = x + y
    for (int y = 0; y < H; y++) {
      int x = k - y;
      if (x < 0 || x >= W) {
        continue;
      }
      const int dy[2] = {0, 1};
      const int dx[2] = {1, 0};
      for (int l = 0; l < 2; l++) {
        int ny = y + dy[l];
        int nx = x + dx[l];
        if (ny >= H || nx >= W) {
          continue;
        }
        long long ncost = cost[y][x] + A[ny][nx];
        if (k + 1 >= K) {
          ncost -= min(*ms[y][x].begin(), A[ny][nx]);
        }
        if (ncost < cost[ny][nx]) {
          cost[ny][nx] = ncost;
          ms[ny][nx] = ms[y][x];
          ms[ny][nx].insert(A[ny][nx]);
          if (k + 1 >= K) {
            ms[ny][nx].erase(ms[ny][nx].begin());
          }
        }
      }
    }
  }
  cout << cost[H - 1][W - 1] << endl;
  return 0;
}
