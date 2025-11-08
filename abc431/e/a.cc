#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
  int T;
  cin >> T;
  const int dy[4] = {0, -1, 0, 1};
  const int dx[4] = {1, 0, -1, 0};
  for (int ti = 0; ti < T; ti++) {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int y = 0; y < H; y++) {
      cin >> S.at(y);
    }
    int K = 4;
    vector<vector<vector<int> > > dist(H, vector<vector<int> > (W, vector<int>(K, INF)));
    priority_queue<tuple<long long, int, int, int>, vector<tuple<long long, int, int, int> >, greater<tuple<long long, int, int, int> > > pq;
    dist[0][0][0] = 0;
    pq.push(make_tuple(0, 0, 0, 0));
    while (!pq.empty()) {
      auto [distu, y, x, k] = pq.top();
      pq.pop();
      if (distu > dist.at(y).at(x).at(k)) {
        continue;  // Garbage
      }
      for (int nk = 0; nk < K; nk++) {
        int ny = y + dy[nk];
        int nx = x + dx[nk];
        if (nx < 0 || nx >= W || ny < 0 || ny >= H) {
          continue;
        }
        // 反射しない
        if (abs(nk - k) == 2) {
          continue;
        }
        // コストを求める
        int cost = 1;
        if (S.at(y).at(x) == 'A') {
          if (nk == k) {
            cost = 0;
          }
        } else if (S.at(y).at(x) == 'B') {
          int mn = min(nk, k);
          int mx = max(nk, k);
          if ((mn == 1 && mx == 2) || (mn == 0 && mx == 3)) {
            cost = 0;
          }
        } else if (S.at(y).at(x) == 'C') {
          int mn = min(nk, k);
          int mx = max(nk, k);
          if ((mn == 0 && mx == 1) || (mn == 2 && mx == 3)) {
            cost = 0;
          }
        }
        if (distu + cost < dist[ny][nx][nk]) {
          dist[ny][nx][nk] = distu + cost;
          pq.push(make_tuple(dist[ny][nx][nk], ny, nx, nk));
        }
      }
    }
    // distが求まった
    int ans = INF;
    {
      // dist[H - 1][W - 1][0]から
      int cost = 1;
      if (S.at(H - 1).at(W - 1) == 'A') {
        cost = 0;
      }
      int now = dist[H - 1][W - 1][0] + cost;
      ans = min(ans, now);
    }
    {
      // dist[H - 1][W - 1][3]から
      int cost = 1;
      if (S.at(H - 1).at(W - 1) == 'B') {
        cost = 0;
      }
      int now = dist[H - 1][W - 1][3] + cost;
      ans = min(ans, now);
    }
    cout << ans << '\n';
  }
  return 0;
}
