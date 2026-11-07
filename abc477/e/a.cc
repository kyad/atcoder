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
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B.at(i);
  }
  vector<long long> U(N);
  U.at(0) = A.at(0);
  for (int i = 1; i < N; i++) {
    U.at(i) = U.at(i - 1) + A.at(i);
  }
  auto dis = [&](int s, int t) {
    if (s == 0) {
      return U.at(t - 1);
    } else {
      return U.at(t - 1) - U.at(s - 1);
    }
  };
  vector<vector<pair<int, long long>>> graph(N + 1);
  for (int u = 0; u < N; u++) {
    int v = (u + 1) % N;
    graph.at(u).push_back(make_pair(v, A.at(u)));
    graph.at(v).push_back(make_pair(u, A.at(u)));
    graph.at(u).push_back(make_pair(N, B.at(u)));
    graph.at(N).push_back(make_pair(u, B.at(u)));
  }
  vector<long long> dist = dijkstra(graph, N);
  for (int qi = 0; qi < Q; qi++) {
    int S, T;
    cin >> S >> T;
    S--; T--;
    long long ans;
    if (S > T) {
      swap(S, T);
    } // S < T
    if (T == N) {
      ans = dist.at(S);
    } else {
      long long d0 = dis(S, T);
      long long d1 = U.at(N - 1) - d0;
      long long d2 = dist.at(S) + dist.at(T);
      ans = min({d0, d1, d2});
    }
    cout << ans << '\n';
  }
  return 0;
}
