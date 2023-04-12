#include <algorithm>
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
  vector<vector<int> > R(M);
  vector<vector<int> > graph(N + M);
  for (int m = 0; m < M; m++) {
    int K;
    cin >> K;
    int s = N + m;  // 超頂点
    for (int k = 0; k < K; k++) {
      int r;
      cin >> r;
      r--;
      graph[r].push_back(s);
      graph[s].push_back(r);
    }
  }
  vector<int> T = bfs(graph, 0);
  for (int n = 0; n < N; n++) {
    int ans = T[n] >= 0 ? T[n] / 2 : -1;
    cout << ans << '\n';
  }
  return 0;
}
