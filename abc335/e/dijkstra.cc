#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

vector<int> dijkstra(vector<vector<int> > graph, const vector<int> A, int start = 0)  {
  int N = graph.size();
  vector<int> dist(N, 0);
  // (-A, dist, 頂点番号u) 大きい順
  using T = tuple<int, int, int>;
  priority_queue<T> pq;  // 大きい順
  dist.at(start) = 1;
  pq.push(make_tuple(-A[start], dist[start], start));
  while (!pq.empty()) {
    int distu = get<1>(pq.top());
    int u = get<2>(pq.top());
    pq.pop();
    if (distu < dist.at(u)) {
      continue;  // Garbage
    }
    for (int v : graph.at(u)) {
      if (A[v] == A[u]) {
        if (distu > dist.at(v)) {
          dist.at(v) = distu;
          pq.push(make_tuple(-A[v], dist.at(v), v));
        }
      } else if (A[v] > A[u]) {
        if (distu + 1 > dist.at(v)) {
          dist.at(v) = distu + 1;
          pq.push(make_tuple(-A[v], dist.at(v), v));
        }
      }
    }
  }
  return dist;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<vector<int> > graph(N);
  for (int m = 0; m < M; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph[U].push_back(V);
    graph[V].push_back(U);
  }
  vector<int> dist = dijkstra(graph, A);
  int ans = dist[N - 1];
  cout << ans << endl;
  return 0;
}
