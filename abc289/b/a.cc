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
  for (int m = 0; m < M; m++) {
    int a;
    cin >> a;
    a--;
    graph.add_edge(a, a + 1);
    graph.add_edge(a + 1, a);
  }
  vector<vector<int> > scc = graph.scc();
  vector<pair<int, int> > ps;
  for (size_t i = 0; i < scc.size(); i++) {
    ps.push_back(make_pair(scc[i][0], i));
  }
  sort(ps.begin(), ps.end());
  vector<int> ans;
  for (size_t i = 0; i < ps.size(); i++) {
    int idx = ps[i].second;
    sort(scc[idx].begin(), scc[idx].end(), greater<int>());
    for (size_t j = 0; j < scc[idx].size(); j++) {
      ans.push_back(scc[idx][j]);
    }
  }
  for (size_t k = 0; k < ans.size(); k++) {
    cout << (ans[k] + 1);
    if (k + 1 == ans.size()) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  return 0;
}
