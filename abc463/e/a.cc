#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <queue>
const long long INF = 4e18;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

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
  int N, M;
  long long Y;
  cin >> N >> M >> Y;
  vector<vector<pair<int, long long> > > graph(N + 1);
  for (int j = 0; j < M; j++) {
    int U, V;
    long long T;
    cin >> U >> V >> T;
    U--; V--;
    graph.at(U).push_back(make_pair(V, T));
    graph.at(V).push_back(make_pair(U, T));
  }
  for (int u = 0; u < N; u++) {
    long long X;
    cin >> X;
    graph.at(u).push_back(make_pair(N, X));
    graph.at(N).push_back(make_pair(u, X + Y));
  }
  vector<long long> dist = dijkstra(graph, 0);
  vector<long long> ans;
  for (int u = 1; u < N; u++) {
    ans.push_back(dist.at(u));
  }
  dump(ans);
  return 0;
}
