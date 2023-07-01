#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, long long> > > graph(N);
  for (int m = 0; m < M; m++) {
    int U, V, W;
    cin >> U >> V >> W;
    U--; V--;
    graph[U].push_back(make_pair(V, W));
    graph[V].push_back(make_pair(U, W));
  }
  int K;
  cin >> K;
  vector<int> A(K);
  for (int k = 0; k < K; k++) {
    cin >> A.at(k);
    A[k]--;
  }
  int D;
  cin >> D;
  vector<long long> X(D + 1, 0);
  for (int d = 1; d <= D; d++) {
    cin >> X.at(d);
  }

  // Dijkstra's algorithm (O|E|log|V|)
  const long long INF64 = 4e18;
  vector<long long> dist(N, INF64);
  vector<int> ans(N, -1);
  vector<bool> vis(N, false);
  priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
  for (int start: A) {
    dist.at(start) = 0;
    pq.push(make_pair(dist.at(start), start));
    ans[start] = 0;
  }

  for (int date = 1; date <= D; date++) {
    queue<pair<long long, int> > qq;
    while (!pq.empty()) {
      long long distu = pq.top().first;
      int u = pq.top().second;
      if (vis[u]) {
        pq.pop();
        continue;  // Garbage
      }
      if (distu > X[date]) {
        break;
      }
      pq.pop();
      if (ans[u] == -1) {
        ans[u] = date;
      }
      vis[u] = true;
      for (pair<int, long long> p : graph.at(u)) {
        int v = p.first;
        long long cost = p.second;
        if (ans[v] == -1) {
          if (distu + cost <= X[date]) {
            dist.at(v) = distu + cost;
            pq.push(make_pair(dist.at(v), v));
          } else {
            qq.push(make_pair(cost, v));
          }
        }
      }
    }
    while (!qq.empty()) {
      pq.push(qq.front());
      qq.pop();
    }
  }

  for (int i = 0; i < N; i++) {
    int now = ans[i];
    cout << now << '\n';
  }

  return 0;
}
