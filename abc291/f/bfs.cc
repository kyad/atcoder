#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

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
      if (S[m] == '1') {
        int v = u + m + 1;
        assert(v < N);
        graph[u].push_back(v);
        graph_inv[v].push_back(u);
      }
    }
  }
  const int INF = 1e9;
  vector<int> dist0 = bfs(graph, 0);
  vector<int> dist1 = bfs(graph_inv, N - 1);
  replace(dist0.begin(), dist0.end(), -1, INF);
  replace(dist1.begin(), dist1.end(), -1, INF);
  for (int k = 1; k < N - 1; k++) {  // 0-index
    int ans = INF;
    for (int m = 0; m < M - 1; m++) {
      int u = k - m - 1;
      if (u < 0) {
        continue;
      }
      for (int v : graph[u]) {
        if (v <= k) {
          continue;
        }
        ans = min(ans, dist0[u] + dist1[v] + 1);
      }
    }
    if (ans >= INF) {
      ans = -1;
    }
    cout << ans << " \n"[k == N - 2];
  }
  return 0;
}
