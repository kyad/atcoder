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
  vector<int> odeg(N, 0);
  UnionFind uf(N);
  for (int m = 0; m < M; m++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    // A <-- B
    odeg[B]++;
    graph[B].push_back(A);
    uf.unite(A, B);
  }
  if (uf.num_unions() != 1) {
    //cerr << "A" << endl;
    cout << -1 << endl;
    return 0;
  }
  int ans = -1;
  for (int u = 0; u < N; u++) {
    if (odeg[u] == 0) {
      if (ans >= 0) {
        //cerr << "B " << endl;
        cout << -1 << endl;
        return 0;
      }
      ans = u;
    }
  }
  cout << (ans + 1) << endl;
  return 0;
}

