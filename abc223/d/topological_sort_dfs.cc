// https://atcoder.jp/contests/abc223/tasks/abc223_d
// WA, it fails for test10

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<bool> seen, finished;
vector<int> order;
bool dfs(const vector<vector<int> > &graph, int v) {
  seen[v] = true;
  for (size_t i = 0; i < graph[v].size(); i++) {
    int w = graph[v][i];
    if (finished[w]) {
      continue;
    } else if (seen[w]) {  // Detect cycle
      return false;
    }
    if (!dfs(graph, w)) {
      return false;
    }
  }
  finished[v] = true;
  order.push_back(v);
  return true;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph(N);
  for (int m = 0; m < M; m++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    graph[A].push_back(B);
  }
  // Lexical order
  for (int n = 0; n < N; n++) {
    sort(graph[n].begin(), graph[n].end(), greater<int>());
  }
  // Topological sort
  seen.assign(N, false);
  finished.assign(N, false);
  order.clear();
  for (int n = N - 1; n >= 0; n--) {
    if (seen[n]) {
      continue;
    }
    if (!dfs(graph, n)) {
      cout << -1 << endl;
      return 0;
    }
  }
  reverse(order.begin(), order.end());
  for (size_t i = 0; i < order.size(); i++) {
    cout << (order[i] + 1) << (i == (order.size() - 1) ? '\n' : ' ');
  }
  return 0;
}
