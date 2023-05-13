#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int H, W, T;
  cin >> H >> W >> T;
  vector<string> A(H);
  for (int y = 0; y < H; y++) {
    cin >> A.at(y);
  }
  // お菓子の場所をさがす
  int sy = -1, sx = -1, gy = -1, gx = -1;
  vector<int> oy, ox;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (A[y][x] == 'S') {
        sy = y;
        sx = x;
      } else if (A[y][x] == 'G') {
        gy = y;
        gx = x;
      } else if (A[y][x] == 'o') {
        oy.push_back(y);
        ox.push_back(x);
      }
    }
  }
  assert(sy >= 0 && sx >= 0 && gy >= 0 && gx >= 0);
  int N = oy.size();
  vector<int> Y, X;
  for (size_t i = 0; i < oy.size(); i++) {
    Y.push_back(oy[i]);
    X.push_back(ox[i]);
  }
  Y.push_back(gy);
  X.push_back(gx);
  Y.push_back(sy);
  X.push_back(sx);
  // 0~N-1:お菓子, N=G, N+1=S
  int M = Y.size();
  const long long INF = 4e18;
  vector<vector<long long> > weight(M, vector<long long>(M, INF)); //weight[i][j]: i->jの最短路
  // distを求めるBFS
  auto bfs = [&](int sy, int sx) {
    vector<vector<int> > dist(H, vector<int>(W, -1));
    queue<pair<int, int> > todo;
    todo.push(make_pair(sy, sx));
    dist[sy][sx] = 0;
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
        if (A[ny][nx] == '#') {
          continue;
        }
        if (dist[ny][nx] >= 0) {
          continue;
        }
        dist[ny][nx] = dist[y][x] + 1;
        todo.push(make_pair(ny, nx));
      }
    }
    return dist;
  };
  for (int i = 0; i < M; i++) {
    vector<vector<int> > dist = bfs(Y[i], X[i]);
    for (int j = 0; j < M; j++) {
      weight[i][j] = dist[Y[j]][X[j]];
      if (weight[i][j] < 0) {
        weight[i][j] = INF;
      }
    }
  }
  // Dijkstra's algorithm for sparse graph (O|E|log|V|)
  // dist[u][s]: sからuに行くまでで、これまでにsを取った
  vector<vector<long long> > dist(M, vector<long long>(1<<N, INF));
  dist[N + 1][0] = 0;  // Start
  // tuple:(dist, u, s)
  priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int> >, greater<tuple<long long, int, int> > > pq;
  pq.push(make_tuple(0, N + 1, 0));
  while (!pq.empty()) {
    long long dist_min = get<0>(pq.top());
    int dist_min_u = get<1>(pq.top());
    int dist_min_s = get<2>(pq.top());
    pq.pop();
    if (dist_min > dist[dist_min_u][dist_min_s]) {
      // garbage
      continue;
    }
    // おかし、ゴールへの遷移
    for (int u = 0; u <= N; u++) {
      int ns = dist_min_s;
      // おかし
      if (u < N) {
        if (dist_min_s>>u&1) {
          continue;
        }
        ns |= (1<<u);
      }
      long long cost = weight[dist_min_u][u];
      if (dist[u][ns] > dist_min + cost) {
        dist[u][ns] = dist_min + cost;
        pq.push(make_tuple(dist[u][ns], u, ns));
      }
    }
  }
  long long dist_min = INF;
  int ans = 0;
  for (int b = 0; b < 1<<N; b++) {
    if (dist[N][b] <= T) {
      dist_min = min(dist_min, dist[N][b]);
      int now = __builtin_popcount(b);
      ans = max(ans, now);
    }
  }
  if (dist_min == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
