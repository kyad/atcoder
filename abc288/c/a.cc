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
  vector<int> count(N, 0);
  UnionFind uf(N);
  for (int m = 0; m < M; m++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    if (uf.issame(A, B)) {
      count.at(uf.root(A))++;
    }
    uf.unite(A, B);
  }
  int ans = 0;
  for (int n = 0; n < N; n++) {
    ans += count.at(n);
  }
  cout << ans << endl;
  return 0;
}
