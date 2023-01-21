#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<long long> A;

vector<vector<int> > dist;  // dist[u][v]: uからvまで行くときの距離
vector<vector<long long> > value;  // value[u][v]: uからvまで行くときの価値の最大値

void bfs(const vector<vector<int> > &graph, int s) {
  //int N = (int)graph.size();
  queue<int> todo;
  //vector<int> dist(N, -1);
  //vector<long long> value(N, 0);
  dist[s][s] = 0;
  todo.push(s);
  value[s][s] = A[s];
  while (!todo.empty()) {
    int v = todo.front();
    todo.pop();
    for (size_t i = 0; i < graph[v].size(); i++) {
      int x = graph[v][i];
      if (dist[s][x] < 0) {
	dist[s][x] = dist[s][v] + 1;
	todo.push(x);
      }
      if (dist[s][x] == dist[s][v] + 1) {
        long long now = value[s][v] + A[x];
        value[s][x] = max(value[s][x], now);
      }
    }
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
  dist.resize(N, vector<int>(N, -1));
  value.resize(N, vector<long long>(N, 0));
  for (int u = 0; u < N; u++) {
    bfs(graph, u);
  }
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    if (dist[U][V] >= 0) {
      cout << dist[U][V] << ' ' << value[U][V] << '\n';
    } else {
      cout << "Impossible" << '\n';
    }
  }
  return 0;
}
