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
  vector<pair<int, pair<int, int> > > A(M);
  for (int m = 0; m < M; m++) {
    int C, L, R;
    cin >> C >> L >> R;
    A[m] = make_pair(C, make_pair(L - 1, R));
  }
  sort(A.begin(), A.end());
  UnionFind uf(N + 1);
  long long ans = 0;
  for (int m = 0; m < M; m++) {
    int cost = A[m].first;
    int u = A[m].second.first;
    int v = A[m].second.second;
    if (uf.issame(u, v)) {
      continue;
    }
    uf.unite(u, v);
    ans += cost;
  }
  if (uf.num_unions() != 1) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
