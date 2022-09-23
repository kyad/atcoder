// https://atcoder.jp/contests/typical90/tasks/typical90_z

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > graph(N);
  for (int n = 0; n < N - 1; n++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  vector<int> color(N, -1);
  auto dfs = [&](auto dfs, int u, int parent) -> void {
    if (parent == -1) {
      color[u] = 0;
    } else {
      assert(color[parent] >= 0);
      color[u] = 1 - color[parent];
    }
    for (int v : graph[u]) {
      if (v == parent) {
        continue;
      }
      dfs(dfs, v, u);
    }
  };
  dfs(dfs, 0, -1);
  int c0 = 0;
  for (int c : color) {
    assert(c >= 0);
    if (c == 0) {
      c0++;
    }
  }
  int c = c0 >= N / 2 ? 0 : 1;
  int count = 0;
  for (int u = 0; u < N; u++) {
    if (color[u] == c) {
      cout << (u + 1);
      if (count == N - 1) {
        cout << '\n';
      } else {
        cout << ' ';
      }
      count++;
      if (count >= N / 2) {
        break;
      }
    }
  }
  return 0;
}
