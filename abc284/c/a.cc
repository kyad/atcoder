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
  for (int m = 0; m < M; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph.add_edge(U, V);
    graph.add_edge(V, U);
  }
  vector<vector<int> > s = graph.scc();
  cout << s.size() << endl;
  return 0;
}
