#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/scc>
using namespace atcoder;

int main() {
  int N, M;
  cin >> N >> M;
  scc_graph graph(N * 2);
  vector<int> deg(N * 2, 0);
  for (int u = 0; u < 2 * N; u += 2) {
    int v = u + 1;
    graph.add_edge(u, v);
    graph.add_edge(v, u);
    deg[u] += 2;
    deg[v] += 2;
  }
  for (int m = 0; m < M; m++) {
    int A, C;
    char B, D;
    cin >> A >> B >> C >> D;
    A--; C--;
    int u = (B == 'R') ? (A * 2) : (A * 2 + 1);
    int v = (D == 'R') ? (C * 2) : (C * 2 + 1);
    graph.add_edge(u, v);
    graph.add_edge(v, u);
    deg[u] += 2;
    deg[v] += 2;
  }
  vector<vector<int> > scc = graph.scc();
  int X = 0;
  int Y = 0;
  for (size_t i = 0; i < scc.size(); i++) {
    int S = scc[i].size();
    int sum = 0;
    for (size_t j = 0; j < scc[i].size(); j++) {
      sum += deg[scc[i][j]];
    }
    if (sum == S * 4) {
      X++;
    } else {
      Y++;
    }
  }
  cout << X << ' ' << Y << endl;
  return 0;
}
