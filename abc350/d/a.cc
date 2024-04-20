#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/scc>
using namespace atcoder;

long long comb2(long long N) { return N * (N - 1) / 2; }

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> odeg(N, 0);
  scc_graph graph(N);
  for (int m = 0; m < M; m++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    graph.add_edge(A, B);
    graph.add_edge(B, A);
    odeg.at(A)++;
  }
  long long ans = 0;
  auto scc = graph.scc();
  for (auto v : scc) {
    long long k = v.size();
    long long now = comb2(k);
    for (int x : v) {
      now -= odeg.at(x);
    }
    assert(now >= 0);
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
