#include <iostream>
#include <atcoder/scc.hpp>
using namespace std;
using namespace atcoder;

long long comb2(int a) {
  long long ans = a;
  ans *= (ans - 1);
  ans /= 2;
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  scc_graph graph(N);
  for (int m = 0; m < M; m++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    graph.add_edge(A, B);
  }
  vector<vector<int> > scc = graph.scc();
  long long ans = 0;
  for (size_t i = 0; i < scc.size(); i++) {
    ans += comb2(scc.at(i).size());
  }
  cout << ans << endl;
  return 0;
}
