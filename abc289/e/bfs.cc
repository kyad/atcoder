#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void testcase() {
  int N, M;
  cin >> N >> M;
  vector<int> C(N, 0);
  for (int n = 0; n < N; n++) {
    cin >> C.at(n);
  }
  vector<vector<int> > graph(N);
  for (int m = 0; m < M; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph[U].push_back(V);
    graph[V].push_back(U);
  }
  vector<int> dist(N * N, -1);
  queue<int> todo;
  auto encode = [&](int u, int v) { return u * N + v; };
  int start = encode(0, N - 1);
  dist[start] = 0;
  todo.push(start);
  while (!todo.empty()) {
    int e = todo.front();
    int u = e / N;
    int v = e % N;
    todo.pop();
    for (int nu : graph[u]) {
      for (int nv : graph[v]) {
        if (C[nu] == C[nv]) {
          continue;
        }
        int x = encode(nu, nv);
        if (dist[x] < 0) {
          dist[x] = dist[e] + 1;
          todo.push(x);
        }
      }
    }
  }
  int ans = dist[encode(N - 1, 0)];
  cout << ans << '\n';
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    testcase();
  }
  return 0;
}
