#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

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
  vector<int> P(N, -1);
  for (int n = 0; n < N - 1; n++) {
    cin >> P.at(n + 1);
    P.at(n + 1)--;
  }

  UnionFind uf(N);
  // uf.root --> minimum value in the uf
  vector<int> mn(N);
  for (int n = 0; n < N; n++) {
    mn[n] = n;
  }

  auto merge = [&](int u, int v) {
    int mn_u = mn[uf.root(u)];
    int mn_v = mn[uf.root(v)];
    uf.unite(u, v);
    mn[uf.root(u)] = min(mn_u, mn_v);
  };
  
  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      while (!uf.issame(u, v)) {
        merge(u, P[u]);
        u = mn[uf.root(P[u])];
      }
    } else {
      int x;
      cin >> x;
      x--;
      int ans = mn[uf.root(x)];
      cout << (ans + 1) << '\n';
    }
  }
  return 0;
}
