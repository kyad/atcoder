#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/scc>
using namespace atcoder;

int main() {
  int N, M;
  cin >> N >> M;
  scc_graph graph(N);
  vector<int> deg(N, 0);
  for (int m = 0; m < M; m++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    graph.add_edge(u, v);
    graph.add_edge(v, u);
    deg[u]++;
    deg[v]++;
  }
  vector<vector<int> > scc = graph.scc();
  bool ans = true;
  for (size_t i = 0; i < scc.size(); i++) {
    int edges = 0;
    for (size_t j = 0; j < scc[i].size(); j++) {
      edges += deg[scc[i][j]];
    }
    assert(edges % 2 == 0);
    edges /= 2;
    int nodes = scc[i].size();
    if (nodes != edges) {
      ans = false;
      break;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
