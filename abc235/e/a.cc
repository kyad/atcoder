// https://atcoder.jp/contests/abc235/tasks/abc235_e

#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

struct UnionFind {
  vector<int> parent, _size;

  UnionFind(int n) : parent(n, -1), _size(n, 1) {}

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

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) {
      return false;
    }
    if (_size[x] < _size[y]) {
      swap(x, y);  // Union by size
    }
    parent[y] = x;
    _size[x] += _size[y];
    return true;
  }

  int size(int x) {
    return _size[root(x)];
  }
};

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  // weight, queue number, u, v
  vector<tuple<int, int, int, int> > edges(M + Q);
  for (int m = 0; m < M; m++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    edges.at(m) = make_tuple(c, -1, a, b);
  }
  for (int q = 0; q < Q; q++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    edges.at(M + q) = make_tuple(w, q, u, v);
  }
  sort(edges.begin(), edges.end());
  vector<int> ans(Q, -1);
  set<int> st;
  UnionFind uf(N);
  for (int i = 0; i < M + Q; i++) {
    int w = get<0>(edges.at(i));
    int q = get<1>(edges.at(i));
    int u = get<2>(edges.at(i));
    int v = get<3>(edges.at(i));
    if (q < 0) {
      uf.unite(u, v);
    } else {
      if (uf.issame(u, v)) {
        ans[q] = 0;
      } else {
        ans[q] = 1;
      }
    }
  }
  for (int q = 0; q < Q; q++) {
    if (ans[q] == 1) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
