#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<pair<int, long long> > > graph(N);
  for (int j = 0; j < M; j++) {
    int U, V;
    long long W;
    cin >> U >> V >> W;
    U--; V--;
    graph.at(U).push_back(make_pair(V, W));
    graph.at(V).push_back(make_pair(U, W));
  }
  vector<long long> D(N, 0);
  for (int k = 0; k < K; k++) {
    int L;
    long long C;
    cin >> L >> C;
    L--;
    D.at(L) = C;
  }
  #include <queue>
  const long long INF = 4e18;

  vector<long long> dist(N, INF);
  priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
  int start = 0;
  dist.at(start) = D.at(start);
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
      if (distu + cost + D.at(v) < dist.at(v)) {
        dist.at(v) = distu + cost + D.at(v);
        pq.push(make_pair(dist.at(v), v));
      }
    }
  }
  long long ans = dist.at(N - 1);
  cout << ans << '\n';
  return 0;
}
