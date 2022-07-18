// https://atcoder.jp/contests/abc221/tasks/abc221_f

#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

// Find far node from u by tree dfs
// Returns {dist, u}
//   dist: distance from first node
//   u: the node id
pair<int, int> dfs_longest(const vector<vector<int> > &graph, int u, int parent = -1, int d = 0) {
  pair<int, int> ans = make_pair(d, u);
  for (size_t i = 0; i < graph.at(u).size(); i++) {
    int v = graph.at(u).at(i);
    if (v == parent) {
      continue;
    }
    ans = max(ans, dfs_longest(graph, v, u, d + 1));
  }
  return ans;
}

// Find Diameter of tree
// Augments
//   graph: tree, 0-indexed
// Returns {D, s, t}
//   D: Diameter
//   s, t: One of edges
tuple<int, int, int> find_tree_diameter(const vector<vector<int> > &graph) {
  pair<int, int> p0 = dfs_longest(graph, 0, -1, 0);
  int s = p0.second;
  pair<int, int> p1 = dfs_longest(graph, s, -1, 0);
  int D = p1.first;
  int t = p1.second;
  return make_tuple(D, s, t);
}

// Find path from s to t by dfs
// Augments
//   graph: tree, 0-indexed
// Returns {D, s, t}
//   D: Diameter
//   s, t: One of edges
vector<int> path;
bool dfs_find_path(const vector<vector<int> > &graph, int s, int t, int parent = -1) {
  bool ans = false;
  if (s == t) {
    path.push_back(s);
    return true;
  }
  for (size_t i = 0; i < graph.at(s).size(); i++) {
    int v = graph.at(s).at(i);
    if (v == parent) {
      continue;
    }
    if (dfs_find_path(graph, v, t, s)) {
      path.push_back(s);
      ans = true;
    }
  }
  return ans;
}

// Count nodes from u with dist=d by tree dfs
// Augments
//   graph: tree, 0-indexed
//   d: dist, >= 0
// Returns: Number of nodes from u with dist=d
int dfs_count(const vector<vector<int> > &graph, int u, int parent, int d) {
  if (d == 0) {
    return 1;
  }
  int ans = 0;
  for (size_t i = 0; i < graph.at(u).size(); i++) {
    int v = graph.at(u).at(i);
    if (v == parent) {
      continue;
    }
    ans += dfs_count(graph, v, u, d - 1);
  }
  return ans;
}

int main() {
  const int MOD = 998244353;
  int N;
  cin >> N;
  vector<vector<int> > graph(N);
  for (int n = 0; n < N - 1; n++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph.at(U).push_back(V);
    graph.at(V).push_back(U);
   }
  auto [D, s, t] = find_tree_diameter(graph);
  dfs_find_path(graph, s, t, -1);
  long long ans;
  if (D % 2 == 1) {
    int cs = path[D / 2];  // 木の中心(s側)
    int ct = path[D / 2 + 1];  // 木の中心(t側)
    long long S = dfs_count(graph, cs, ct, D / 2);
    long long T = dfs_count(graph, ct, cs, D / 2);
    ans = S * T;
    ans %= MOD;
  } else {
    int c = path[D / 2];  // 木の中心
    ans = 1;
    long long sub = 1;
    for (int u : graph[c]) {
      long long m = dfs_count(graph, u, c, D / 2 - 1);
      ans *= (m + 1);
      ans %= MOD;
      sub += m;
      sub %= MOD;
    }
    ans += (MOD - sub);
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
