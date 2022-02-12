// https://atcoder.jp/contests/abc237/tasks/abc237_e

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> H(N);
  for (int n = 0; n < N; n++) {
    cin >> H.at(n);
  }
  vector<vector<pair<int, int> > > graph(N);
  for (int m = 0; m < M; m++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    graph[u].push_back(make_pair(v, max(0, H[v] - H[u])));
    graph[v].push_back(make_pair(u, max(0, H[u] - H[v])));
  }
  // Dijkstra's algorithm for sparse graph (O|E|log|V|)
  const long long INF = (long long)100000000 * 200000 + 1;
  vector<long long> dist(N, INF);
  dist.at(0) = 0;
  priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
  pq.push(make_pair(0, 0));
  while (!pq.empty()) {
    long long dist_min = pq.top().first;
    int dist_min_idx = pq.top().second;
    pq.pop();
    if (dist_min > dist.at(dist_min_idx)) {
      // garbage
      continue;
    }
    vector<pair<int, int> > edges = graph.at(dist_min_idx);
    for (size_t i = 0; i < edges.size(); i++) {
      int v = edges.at(i).first;
      int cost = edges.at(i).second;
      if (dist.at(v) > dist_min + cost) {
        dist.at(v) = dist_min + cost;
        pq.push(make_pair(dist.at(v), v));
      }
    }
  }
  long long ans = 0LL;
  for (int n = 1; n < N; n++) {
    ans = max(ans, H[0] - H[n] - dist[n]);
  }
  cout << ans << endl;
  return 0;
}
