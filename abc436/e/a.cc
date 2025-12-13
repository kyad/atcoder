#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <atcoder/scc>
using namespace atcoder;

long long comb2(long long N) { return N * (N - 1) / 2; }

int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  scc_graph graph(N);
  for (int u = 0; u < N; u++) {
    int P;
    cin >> P;
    P--;
    graph.add_edge(u, P);
  }
  vector<vector<int> > scc = graph.scc();
  long long ans = 0;
  for (auto vs: scc) {
    long long size = vs.size();
    long long now = comb2(size);
    ans += now;
  }
  cout << ans << '\n';
  return 0;
}
