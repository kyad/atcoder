#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<long long> A;

void bfs(const vector<vector<int> > &graph, int s, int t) {
  int N = (int)graph.size();
  queue<int> todo;
  vector<int> dist(N, -1);
  vector<long long> value(N, 0);  // value[u]: uまで行くときの価値の最大値
  dist[s] = 0;
  todo.push(s);
  value[s] = A[s];
  while (!todo.empty()) {
    int v = todo.front();
    todo.pop();
    for (size_t i = 0; i < graph[v].size(); i++) {
      int x = graph[v][i];
      if (dist[x] < 0) {
	dist[x] = dist[v] + 1;
	todo.push(x);
      }
      if (dist[x] == dist[v] + 1) {
        long long now = value[v] + A[x];
        value[x] = max(value[x], now);
      }
    }
  }
  if (dist[t] >= 0) {
    cout << dist[t] << ' ' << value[t] << '\n';
  } else {
    cout << "Impossible" << '\n';
  }
}

int main() {
  int N;
  cin >> N;
  A.resize(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<vector<int> > graph(N);
  for (int u = 0; u < N; u++) {
    string S;
    cin >> S;
    for (int v = 0; v < N; v++) {
      if (S[v] == 'Y') {
        graph[u].push_back(v);
      }
    }
  }
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    bfs(graph, U, V);
  }
  return 0;
}
