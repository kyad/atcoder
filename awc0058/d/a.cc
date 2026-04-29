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
vector<long long> dijkstra(const vector<vector<pair<int, long long> > >& graph, int start)  {
  int N = graph.size();
  vector<long long> dist(N, INF);
  using P = pair<long long, int>;
  priority_queue<P, vector<P>, greater<P>> pq;
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
  int N, M, K;
  cin >> N >> M >> K;
  K--;
  vector<vector<pair<int, long long> > > graph(N);
  for (int j = 0; j < M; j++) {
    int U, V;
    long long C;
    cin >> U >> V >> C;
    U--; V--;
    graph.at(U).push_back(make_pair(V, C));
    graph.at(V).push_back(make_pair(U, C));
  }
  vector<long long> dist0 = dijkstra(graph, 0);
  vector<long long> dist1 = dijkstra(graph, N - 1);
  long long ans0 = dist0.at(K);
  long long ans1 = dist1.at(K);
  long long ans;
  if (ans0 == INF || ans1 == INF) {
    ans = -1;
  } else {
    ans = ans0 + ans1;
  }
  cout << ans << '\n';
  return 0;
}
