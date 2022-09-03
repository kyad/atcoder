#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  const long long INF = 4e18;
  int N, M;
  cin >> N >> M;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<vector<int> > graph(N);
  for (int m = 0; m < M; m++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<long long> cost(N, 0);
  for (int n = 0; n < N; n++) {
    for (size_t i = 0; i < graph.at(n).size(); i++) {
      int v = graph.at(n).at(i);
      cost.at(n) += A.at(v);
    }
  }
  vector<bool> deleted(N, false);
  priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
  for (int u = 0; u < N; u++) {
    pq.push(make_pair(cost[u], u));
  }
  long long ans = -INF;
  int count = 0;
  while (true) {
    long long c = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (deleted[u]) {
      continue;
    }
    deleted[u] = true;
    ans = max(ans, c);
    for (size_t i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i];
      cost[v] -= A[u];
      pq.push(make_pair(cost[v], v));
    }
    count++;
    if (count >= N) {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
