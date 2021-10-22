// https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_e

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 10000 * 5000 + 1;
vector<int> dijkstra_dense(vector<vector<pair<int, int> > > graph, int start) {
  int N = (int)graph.size();
  vector<bool> used(N, false);
  vector<int> dist(N, INF);
  dist[start] = 0;
  for (int i = 0; i < N; i++) {
    int dist_min = INF;
    int dist_min_idx = -1;
    for (int j = 0; j < N; j++) {
      if (!used[j] && dist[j] < dist_min) {
        dist_min = dist[j];
        dist_min_idx = j;
      }
    }
    if (dist_min_idx == -1) {
      break;
    }
    for (size_t e = 0; e < graph[dist_min_idx].size(); e++) {
      if (dist[graph[dist_min_idx][e].first] > dist_min + graph[dist_min_idx][e].second) {
        dist[graph[dist_min_idx][e].first] = dist_min + graph[dist_min_idx][e].second;
      }
    }
    used[dist_min_idx] = true;
  }
  return dist;
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> C(N), R(N);
  for (int n = 0; n < N; n++) {
    cin >> C.at(n) >> R.at(n);
  }
  vector<vector<int> > graph0(N);
  for (int k = 0; k < K; k++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    graph0[A].push_back(B);
    graph0[B].push_back(A);
  }
  vector<vector<pair<int, int > > > graph1(N);
  for (int n = 0; n < N; n++) {
    // BFS
    queue<int> todo;
    todo.push(n);
    vector<int> dist(N, -1);
    dist[n] = 0;
    while (!todo.empty()) {
      int u = todo.front();
      todo.pop();
      for (size_t i = 0; i < graph0[u].size(); i++) {
        int v = graph0[u][i];
        if (dist[v] >= 0) {
          continue;
        }
        dist[v] = dist[u] + 1;
        todo.push(v);
      }
    }
    for (int i = 0; i < N; i++) {
      if (dist[i] <= R[n]) {
        graph1[n].push_back(make_pair(i, C[n]));
      }
    }
  }
  vector<int> dist = dijkstra_dense(graph1, 0);
  cout << dist[N - 1] << endl;
  return 0;
}
