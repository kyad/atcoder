#include <algorithm>
#include <cassert>
#include <iostream>
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
  int N, M, X;
  cin >> N >> M >> X;
  vector<vector<pair<int, long long> > > graph(N * 2);
  for (int m = 0; m < M; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph.at(U).push_back(make_pair(V, 1));
    graph.at(V + N).push_back(make_pair(U + N, 1));
  }
  for (int u = 0; u < N; u++) {
    graph.at(u).push_back(make_pair(u + N, X));
    graph.at(u + N).push_back(make_pair(u, X));
  }
  vector<long long> dist = dijkstra(graph, 0);
  long long ans = min(dist.at(N - 1), dist.at(N * 2 - 1));
  cout << ans << endl;
  return 0;
}
