#include <iostream>
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
  int N, M, E;
  cin >> N >> M >> E;
  vector<pair<int, int> > edges(E);
  for (int e = 0; e < E; e++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    edges[e] = make_pair(U, V);
  }

  int Q;
  cin >> Q;
  vector<bool> remained(E, true);
  vector<int> X(Q);
  for (int q = 0; q < Q; q++) {
    cin >> X.at(q);
    X.at(q)--;
    remained[X.at(q)] = false;
  }
  
  UnionFind uf(N + M);
  for (int i = N + 1; i <= N + M - 1; i++) {
    uf.unite(N, i);
  }

  for (int e = 0; e < E; e++) {
    if (remained[e]) {
      uf.unite(edges[e].first, edges[e].second);
    }
  }

  vector<int> ans(Q, 0);
  for (int q = 0; q < Q; q++) {
    ans[Q - 1 - q] = uf.size(N) - M;
    int e = X[Q - 1 - q];
    uf.unite(edges[e].first, edges[e].second);
  }

  for (int q = 0; q < Q; q++) {
    cout << ans[q] << endl;
  }
  return 0;
}
