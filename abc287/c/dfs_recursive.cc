#include <cassert>
#include <iostream>
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
    graph.at(U).push_back(V);
    graph.at(V).push_back(U);
  }
  // 連結性の確認
  vector<bool> visited(N, false);
  auto dfs = [&](auto dfs, int u) -> void {
    visited[u] = true;
    for (int v : graph[u]) {
      if (visited[v]) {
        continue;
      }
      dfs(dfs, v);
    }
  };
  dfs(dfs, 0);
  bool ok = true;
  for (int u = 0; u < N; u++) {
    if (!visited[u]) {
      ok = false;
    }
  }
  if (!ok) {
    cout << "No" << endl;
    return 0;
  }

  int deg1 = 0;
  int deg2 = 0;
  for (int u = 0; u < N; u++) {
    if (graph.at(u).size() == 1) {
      deg1++;
    } else if (graph.at(u).size() == 2) {
      deg2++;
    }
  }
  if (deg1 == 2 && deg2 == N - 2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
