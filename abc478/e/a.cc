// https://www.youtube.com/watch?v=6sTl_qFCwW0&t=5470s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <atcoder/scc>
using namespace atcoder;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0, int end = -1) {
  if (end < 0) {
    end = x.size();
  }
  for (int i = start; i < end; i++) {
    cout << x.at(i) << (i + 1 == end ? '\n' : ' ');
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  scc_graph graph(N);
  vector<pair<int, int>> edges;
  for (int qi = 0; qi < Q; qi++) {
    int t, u, v;
    cin >> t >> u >> v;
    u--; v--;
    graph.add_edge(u, v);
    if (t == 1) {
      edges.push_back(make_pair(u, v));
    }
  }
  vector<vector<int>> scc = graph.scc();
  vector<int> ans(N);
  for (int i = 0; i < (int)scc.size(); i++) {
    for (int u : scc.at(i)) {
      ans.at(u) = i + 1;
    }
  }
  for (auto [u, v] : edges) {
    if (ans.at(u) == ans.at(v)) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  dump(ans);
  return 0;
}
