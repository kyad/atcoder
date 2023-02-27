#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfs(const vector<vector<int> > &graph, int s) {
  int N = (int)graph.size();
  queue<int> todo;
  vector<int> dist(N, -1);
  dist[s] = 0;
  todo.push(s);
  while (!todo.empty()) {
    int v = todo.front();
    todo.pop();
    for (size_t i = 0; i < graph[v].size(); i++) {
      int x = graph[v][i];
      if (dist[x] < 0) {
	dist[x] = dist[v] + 1;
	todo.push(x);
      }
    }
  }
  return dist;
}


int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph(N);
  vector<vector<int> > graph_inv(N);
  for (int u = 0; u < N; u++) {
    string S;
    cin >> S;
    for (int m = 0; m < M; m++) {
      int v = u + m + 1;
      if (v >= N) {
        break;
      }
      if (S[m] == '1') {
        graph[u].push_back(v);
        graph_inv[v].push_back(u);
      }
    }
  }
  vector<int> dist0 = bfs(graph, 0);
  vector<int> dist1 = bfs(graph_inv, N - 1);
  const int INF = 1e9;
  for (int k = 1; k < N - 1; k++) {  // 0-index
    int ans = INF;
    for (int m = 0; m < M - 1; m++) {
      int u = k - m - 1;
      if (u < 0) {
        continue;
      }
      if (dist0[u] < 0) {
        continue;
      }
      for (int v : graph[u]) {
        int now = dist0[u] + 1;
        if (v <= k) {
          continue;
        }
        if (dist1[v] < 0) {
          continue;
        }
        now += dist1[v];
        ans = min(ans, now);
      }
    }
    if (ans == INF) {
      ans = -1;
    }
    cout << ans << " \n"[k == N - 2];
  }
  return 0;
}
