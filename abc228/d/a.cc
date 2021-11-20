#include <algorithm>
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
    // if (_size[x] < _size[y]) {
    //   swap(x, y);  // Union by size
    // }
    parent[y] = x;
    _size[x] += _size[y];
    return true;
  }

  int size(int x) {
    return _size[root(x)];
  }
};

int main() {
  const int N = 1048576;
  vector<long long> A(N, -1);
  UnionFind uf(N);
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    long long t, x;
    cin >> t >> x;
    if (t == 1) {
      int h = x % N;
      int index = uf.root(h);
      A[index] = x;
      uf.unite((index + 1) % N, index);
    } else {
      cout << A[x % N] << endl;
    }
  }
  return 0;
}
