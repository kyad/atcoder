// https://atcoder.jp/contests/arc164/editorial/6633

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
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph(N);
  for (int m = 0; m < M; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph[U].push_back(V);
    graph[V].push_back(U);
  }
  vector<int> color(N);
  for (int n = 0; n < N; n++) {
    cin >> color.at(n);
  }

  UnionFind uf(N);
  for (int u = 0; u < N; u++) {
    for (int v : graph[u]) {
      if (color[u] != color[v]) {
        uf.unite(u, v);
      }
    }
  }
  for (int u = 0; u < N; u++) {
    for (int v : graph[u]) {
      if (color[u] == color[v]) {
        if (uf.issame(u, v)) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
