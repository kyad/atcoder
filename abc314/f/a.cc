#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
// modint
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}

using Prob = mint;
//using Prob = double;

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

struct UnionFind {
  vector<int> parent, _size;
  int _num_unions;

  UnionFind(int n) : parent(n, -1), _size(n, 1), _num_unions(n) {}

  int root(int x) {
    if (parent[x] == -1) {
      return x;
    } else {
      //return root(parent[x]);  // O(logN)
      return parent[x] = root(parent[x]);  // O(alpha(N))
    }
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool unite(int x, int y) {  // xが親
    x = root(x);
    y = root(y);
    if (x == y) {
      return false;
    }
#if 0
    if (_size[x] < _size[y]) {
      swap(x, y);  // Union by size
    }
#endif
    parent[y] = x;
    _size[x] += _size[y];
    _num_unions--;
    return true;
  }

  int size(int x) {
    return _size[root(x)];
  }

  int num_unions() {  // unionの数(ひとまとまりになっているグループの数)を返す
    return _num_unions;
  }
};

int main() {
  int N;
  cin >> N;
  UnionFind uf(2 * N - 1);  // グラフ構築用
  UnionFind uf2(N);  // 確率計算用
  // グラフ構築
  vector<vector<pair<int, Prob> > > graph(2 * N - 1);
  for (int parent = N; parent <= 2 * N - 2; parent++) {
    int P, Q;
    cin >> P >> Q;
    P--; Q--;
    const int u = uf.root(P);
    const int v = uf.root(Q);
    const int sz_p = uf2.size(P);
    const int sz_q = uf2.size(Q);
    const Prob prob_u = (Prob)sz_p / (sz_p + sz_q);
    const Prob prob_v = (Prob)sz_q / (sz_p + sz_q);
    graph.at(parent).push_back(make_pair(u, prob_u));
    graph.at(parent).push_back(make_pair(v, prob_v));
    // 更新。parentが親になるようにunite
    uf.unite(parent, P);
    uf.unite(parent, Q);
    uf2.unite(P, Q);
  }
  // dfs
  vector<Prob> E(N);
  Prob cost = 0;
  auto dfs = [&](auto dfs, int u) -> void {
    if (graph.at(u).size() == 0) {  // leaf
      assert(0 <= u && u < N);
      E[u] = cost;
      return;
    }
    assert(N <= u && u < 2 * N - 1);
    assert(graph[u].size() == 2);
    for (auto [v, weight] : graph[u]) {
      cost += weight;
      dfs(dfs, v);
      cost -= weight;
    }
  };
  dfs(dfs, 2 * N - 2);
  dumpvec(E);
  return 0;
}
