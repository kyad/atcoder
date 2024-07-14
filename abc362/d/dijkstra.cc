#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<vector<pair<int, long long> > > graph(N);
  for (int j = 0; j < M; j++) {
    int U, V;
    long long B;
    cin >> U >> V >> B;
    U--; V--;
    graph[U].push_back(make_pair(V, B));
    graph[V].push_back(make_pair(U, B));
  }

  const long long INF = 4e18;

  vector<long long> dist(N, INF);
  priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
  int start = 0;
  dist.at(start) = A.at(start);
  pq.push(make_pair(dist.at(start), start));
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
      if (distu + cost + A.at(v) < dist.at(v)) {
        dist.at(v) = distu + cost + A.at(v);
        pq.push(make_pair(dist.at(v), v));
      }
    }
  }

  for (int n = 1; n < N; n++) {
    cout << dist.at(n) << " \n"[n + 1 == N];
  }
  return 0;
}
