// https://atcoder.jp/contests/abc209/tasks/abc209_d

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > graph;
vector<int> color;

void dfs(int u, int parent) {
  if (parent < 0) {  // Root
    color[u] = 0;
  } else {
    color[u] = 1 - color[parent];
  }
  for (size_t i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (v == parent) {
      continue;
    }
    dfs(v, u);
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  graph.resize(N);
  for (int n = 0; n < N - 1; n++) {
    int a, b;
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }
  color.assign(N, 0);
  dfs(0, -1);
  for (int q = 0; q < Q; q++) {
    int c, d;
    cin >> c >> d;
    cout << (color[c - 1] == color[d - 1] ? "Town" : "Road") << endl;
  }
  return 0;
}

