// https://atcoder.jp/contests/abc244/tasks/abc244_f

#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  const int INF = INT_MAX;
  int N, M;
  cin >> N >> M;
  int N2 = 1<<N;
  vector<vector<int> > graph(N);
  for (int m = 0; m < M; m++) {
    int U, V;
    cin >> U >> V;
    U--;
    V--;
    graph.at(U).push_back(V);
    graph.at(V).push_back(U);
  }
  queue<pair<int, int> > todo;
  vector<vector<int> > dist(N2, vector<int>(N, INF));
  todo.push(make_pair(0, 0));
  dist[0][0] = 0;
  for (int v = 0; v < N; v++) {
    todo.push(make_pair(1<<v, v));
    dist[1<<v][v] = 1;
  }
  while (!todo.empty()) {
    int b = todo.front().first;
    int v = todo.front().second;
    todo.pop();
    for (size_t i = 0; i < graph[v].size(); i++) {
      int nv = graph[v][i];
      int nb = b ^ (1<<nv);
      if (dist[nb][nv] == INF) {
        dist[nb][nv] = dist[b][v] + 1;
        todo.push(make_pair(nb, nv));
      }
    }
  }
  long long ans = 0;
  for (int b = 0; b < N2; b++) {
    int now = INF;
    for (int v = 0; v < N; v++) {
      now = min(now, dist[b][v]);
    }
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
