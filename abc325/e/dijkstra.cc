#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


#include <queue>
const long long INF = 4e18;

/**
 * Dijkstra's algorithm
 * 計算量：(O|E|log|V|)
 * 使用例：
 *   vector<long long> dist = dijstra(graph, start);
 *   long long ans = *min_element(dist.begin(), dist.end());
 */
vector<long long> dijkstra(vector<vector<pair<int, long long> > > graph, int start)  {
  int N = graph.size();
  vector<long long> dist(N, INF);
  priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
  dist.at(start) = 0;
  pq.push(make_pair(0, start));
  while (!pq.empty()) {
    long long distu = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (distu > dist.at(u)) {
      continue;  // Garbage
    }
    for (pair<int, long long> p : graph.at(u)) {
      int v = p.first;
      long long cost = p.second;
      if (distu + cost < dist.at(v)) {
        dist.at(v) = distu + cost;
        pq.push(make_pair(dist.at(v), v));
      }
    }
  }
  return dist;
}

int main() {
  int N;
  long long A, B, C;
  cin >> N >> A >> B >> C;
  vector<vector<long long> > D(N, vector<long long>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> D.at(i).at(j);
    }
  }

  vector<vector<pair<int, long long> > > graph0(N);
  for (int u = 0; u < N; u++) {
    for (int v = 0; v < N; v++) {
      long long dist = D[u][v] * A;
      graph0[u].push_back(make_pair(v, dist));
    }
  }

  vector<vector<pair<int, long long> > > graph1(N);
  for (int u = 0; u < N; u++) {
    for (int v = 0; v < N; v++) {
      long long dist = 0;
      if (u != v) {
        dist = D[u][v] * B + C;
      }
      graph1[u].push_back(make_pair(v, dist));
    }
  }

  vector<long long> dist0 = dijkstra(graph0, 0);
  vector<long long> dist1 = dijkstra(graph1, N - 1);
  long long ans = INF;
  for (int u = 0; u < N; u++) {
    long long now = dist0.at(u) + dist1.at(u);
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
