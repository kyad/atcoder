// https://atcoder.jp/contests/arc150/tasks/arc150_c

#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int> > graph(N);
  for (int m = 0; m < M; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph[U].push_back(V);
    graph[V].push_back(U);
  }
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<int> B(K + 1, 0);  // 1-indexed
  for (int k = 1; k <= K; k++) {
    cin >> B.at(k);
  }

  // Dijkstra's algorithm for sparse graph (O|E|log|V|)
  const long long INF = 4e18;
  vector<long long> dist(N, INF);  // dist[i]: iを通るどんなルートでも達成できるB[i]のi 
  dist.at(0) = A[0] == B[1] ? 1 : 0;
  priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
  pq.push(make_pair(dist[0], 0));
  while (!pq.empty()) {
    long long dist_min = pq.top().first;
    int dist_min_idx = pq.top().second;
    pq.pop();
    if (dist_min > dist.at(dist_min_idx)) {
      // garbage
      continue;
    }
    vector<int> edges = graph.at(dist_min_idx);
    for (size_t i = 0; i < edges.size(); i++) {
      int v = edges.at(i);

      int cost = 0;
      if (dist_min + 1 <= K && A[v] == B[dist_min + 1]) {
        cost++;
      }

      if (dist.at(v) > dist_min + cost) {
        dist.at(v) = dist_min + cost;
        pq.push(make_pair(dist.at(v), v));
      }
    }
  }

  bool ans = dist[N - 1] == K;
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
