#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph(N);
  for (int m = 0; m < M; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph[U].push_back(V);
    graph[V].push_back(U);
  }
  int K;
  cin >> K;
  vector<int> P(K), D(K);
  for (int k = 0; k < K; k++) {
    cin >> P.at(k) >> D.at(k);
    P[k]--;
  }

  // 0: 白, 1: 黒
  vector<int> color(N, 1);

  // 必要条件を調べるbfs
  auto bfs1 = [&](int p, int d) -> void {
    queue<int> todo;
    vector<int> dist(N, -1);
    dist[p] = 0;
    todo.push(p);
    while (!todo.empty()) {
      int v = todo.front();
      todo.pop();
      if (dist[v] < d) {
        color[v] = 0;
      } else {
        assert(dist[v] == d);
        return;
      }
      for (int x: graph[v]) {
        if (dist[x] < 0) {
          dist[x] = dist[v] + 1;
          todo.push(x);
        }
      }
    }
  };
  for (int k = 0; k < K; k++) {
    bfs1(P[k], D[k]);
  }

  // 十分条件を調べるbfs
  auto bfs2 = [&](int p, int d) -> bool {
    queue<int> todo;
    vector<int> dist(N, -1);
    dist[p] = 0;
    todo.push(p);
    while (!todo.empty()) {
      int v = todo.front();
      todo.pop();
      if (dist[v] < d) {
        if (color[v] == 1) {
          return false;
        }
      } else if (dist[v] == d) {
        if (color[v] == 1) {
          return true;
        }
        continue;
      }
      assert(dist[v] < d);
      for (int x: graph[v]) {
        if (dist[x] < 0) {
          dist[x] = dist[v] + 1;
          todo.push(x);
        }
      }
    }
    // color[v] == 0 for all v s.t. dist[v] == d
    return false;
  };

  bool ans = true;
  for (int k = 0; k < K; k++) {
    bool now = bfs2(P[k], D[k]);
    if (!now) {
      ans = false;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  if (ans) {
    for (int n = 0; n < N; n++) {
      cout << color[n];
      if (n == N - 1) {
        cout << '\n';
      }
    }
  }
  return 0;
}
