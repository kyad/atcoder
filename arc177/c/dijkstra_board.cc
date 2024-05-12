#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C.at(i);
  }
  const long long INF = 1e18;
  const int dy[4] = {1, 0, -1, 0};
  const int dx[4] = {0, 1, 0, -1};
  auto f = [&](int sy, int sx, int gy, int gx, char color) -> long long {
    vector<vector<long long> > dist(N, vector<long long>(N, INF));
    dist[sy][sx] = 0;
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int> >, greater<tuple<long long, int, int> > > pq;
    pq.push(make_tuple(0, sy, sx));  // dist, y, x
    while (!pq.empty()) {
      long long dist_min = get<0>(pq.top());
      int dist_min_y = get<1>(pq.top());
      int dist_min_x = get<2>(pq.top());
      pq.pop();
      if (dist_min > dist[dist_min_y][dist_min_x]) {
        // garbage
        continue;
      }
    
      for (size_t k = 0; k < 4; k++) {
        int ny = dist_min_y + dy[k];
        int nx = dist_min_x + dx[k];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
          continue;
        }
        long long cost = (C[ny][nx] == color ? 0 : 1);
        if (dist[ny][nx] > dist_min + cost) {
          dist[ny][nx] = dist_min + cost;
          pq.push(make_tuple(dist[ny][nx], ny, nx));
        }
      }
    }
    return dist[gy][gx];
  };
  long long r = f(0, 0, N - 1, N - 1, 'R');
  long long b = f(0, N - 1, N - 1, 0, 'B');
  long long ans = r + b;
  cout << ans << endl;
  return 0;
}
