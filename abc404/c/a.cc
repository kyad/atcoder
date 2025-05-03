#include <algorithm>
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
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph.add_edge(U, V);
    graph.add_edge(V, U);
    deg.at(U)++;
    deg.at(V)++;
  }
  if (N != M) {
    cout << "No" << endl;
    return 0;
  }

  for (int u = 0; u < N; u++) {
    if (deg.at(u) != 2) {
      cout << "No" << endl;
      return 0;
    }
  }

  vector<vector<int> > scc = graph.scc();

  if (scc.size() == 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
