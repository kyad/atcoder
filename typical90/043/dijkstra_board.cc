#include <cassert>
#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  int rs, cs;
  cin >> rs >> cs;
  rs--; cs--;
  int rt, ct;
  cin >> rt >> ct;
  rt--; ct--;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }

  // Dijkstra's algorithm for sparse graph (O|E|log|V|)
  const long long INF = 4e18;
  vector<vector<vector<long long> > > dist(H, vector<vector<long long> > (W, vector<long long>(4, INF)));
  // dist, y, x, direction
  priority_queue<tuple<long long, int, int, int>,
                 vector<tuple<long long, int, int, int> >,
                 greater<tuple<long long, int, int, int> > > pq;
  for (int d = 0; d < 4; d++) {
    dist[rs][cs][d] = 0;
    pq.push(make_tuple(0, rs, cs, d));
  }
  while (!pq.empty()) {
    long long dist_min = get<0>(pq.top());
    int dist_min_y = get<1>(pq.top());
    int dist_min_x = get<2>(pq.top());
    int dist_min_d = get<3>(pq.top());
    pq.pop();
    if (dist_min > dist[dist_min_y][dist_min_x][dist_min_d]) {
      // garbage
      continue;
    }
    int dy[4] = {0, -1, 0, 1};
    int dx[4] = {1, 0, -1, 0};
    for (int d = 0; d < 4; d++) {
      int ny = dist_min_y + dy[d];
      int nx = dist_min_x + dx[d];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W || S[ny][nx] == '#') {
        continue;
      }
      int cost = (dist_min_d == d ? 0 : 1);
      if (dist[ny][nx][d] > dist_min + cost) {
        dist[ny][nx][d] = dist_min + cost;
        pq.push(make_tuple(dist[ny][nx][d], ny, nx, d));
      }
    }
  }
  long long ans = INF;
  for (int d = 0; d < 4; d++) {
    ans = min(ans, dist[rt][ct][d]);
  }
  assert(ans != INF);
  cout << ans << endl;
  return 0;
}
