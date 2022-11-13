#include <deque>
#include <iostream>
#include <vector>
using namespace std;

const long long INF = 4e18;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<pair<int, int> > > graph(N);
  for (int m = 0; m < M; m++) {
    int u, v, a;
    cin >> u >> v >> a;
    u--; v--;
    graph[u].push_back(make_pair(v, a));
    graph[v].push_back(make_pair(u, a));
  }
  vector<int> S(N, false);
  for (int k = 0; k < K; k++) {
    int s;
    cin >> s;
    s--;
    S[s] = true;
  }
  // 01-bfs
  vector<vector<long long> > dist(N, vector<long long>(2, INF));
  deque<pair<long long, pair<int, int> > > q;
  dist[0][0] = 0;
  q.push_back(make_pair(0, make_pair(0, 0)));
  if (S[0]) {
    dist[0][1] = 0;
    q.push_back(make_pair(0, make_pair(0, 1)));
  }
  while (!q.empty()) {
    long long dist_min = q.front().first;
    int dist_min_u = q.front().second.first;
    int dist_min_j = q.front().second.second;
    q.pop_front();
    if (dist_min > dist[dist_min_u][dist_min_j]) {
      // garbage
      continue;
    }
    const int cost = 1;
    for (auto [v, a] : graph.at(dist_min_u)) {
      if (dist_min_j + a != 1) {
        continue;
      }
      // 押さない
      if (dist[v][dist_min_j] > dist_min + cost) {
        dist[v][dist_min_j] = dist_min + cost;
        q.push_back(make_pair(dist[v][dist_min_j], make_pair(v, dist_min_j)));
      }
      // 押す
      if (S[v]) {
        int nj = 1 - dist_min_j;
        if (dist[v][nj] > dist_min + cost) {
          dist[v][nj] = dist_min + cost;
          q.push_back(make_pair(dist[v][nj], make_pair(v, nj)));
        }
      }
    }
  }
  long long ans = min(dist[N - 1][0], dist[N - 1][1]);
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
