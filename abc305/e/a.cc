#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, const T b) { a = max(a, b); }
// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

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
  // dp[n]: nにいくときのHPの最大値

  const long long INF = 1e18;
  vector<long long> dist(N, -INF);
  priority_queue<pair<long long, int> > pq;
  for (int k = 0; k < K; k++) {
    int P;
    long long H;
    cin >> P >> H;
    P--;
    dist[P] = H;
    pq.push(make_pair(H, P));
  }
  while (!pq.empty()) {
    long long dist_max = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (dist_max < dist.at(u)) {
      // garbage
      continue;
    }
    vector<int> edges = graph.at(u);
    for (size_t i = 0; i < edges.size(); i++) {
      int v = edges.at(i);
      int cost = 1;
      if (dist.at(v) < dist_max - cost) {
        dist.at(v) = dist_max - cost;
        pq.push(make_pair(dist.at(v), v));
      }
    }
  }
  vector<int> ans;
  for (int u = 0; u < N; u++) {
    if (dist[u] >= 0) {
      ans.push_back(u + 1);
    }
  }
  cout << ans.size() << endl;
  dumpvec(ans);
  return 0;
}
