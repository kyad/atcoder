#include <cassert>
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
  int N, M;
  cin >> N >> M;
  vector<int> U(M), V(M);
  for (int m = 0; m < M; m++) {
    cin >> U.at(m) >> V.at(m);
    U[m]--; V[m]--;
  }
  int K;
  cin >> K;
  vector<bool> X(M, false);
  for (int k = 0; k < K; k++) {
    int x;
    cin >> x;
    x--;
    X.at(x) = true;
  }
  UnionFind uf(N);
  for (int m = 0; m < M; m++) {
    if (!X[m]) {
      uf.unite(U[m], V[m]);
    }
  }
  vector<int> deg(N, 0);
  for (int m = 0; m < M; m++) {
    if (X[m]) {
      deg[uf.root(U[m])]++;
      deg[uf.root(V[m])]++;
    }
  }
  int odd = 0;
  for (int n = 0; n < N; n++) {
    if (deg[n] % 2) {
      odd++;
    }
  }
  bool ans = odd <= 2;
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
