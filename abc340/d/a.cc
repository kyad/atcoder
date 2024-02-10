#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

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
  cin >> N;
  vector<vector<pair<int, long long> > > graph(N);
  for (int u = 0; u < N - 1; u++) {
    int A, B, X;
    cin >> A >> B >> X;
    X--;
    graph[u].push_back(make_pair(u + 1, A));
    graph[u].push_back(make_pair(X, B));
  }
  vector<long long> dist = dijkstra(graph, 0);
  long long ans = dist[N - 1];
  cout << ans << endl;
  return 0;
}
