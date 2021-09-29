// https://atcoder.jp/contests/abc120/tasks/abc120_d

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
  vector<int> A(M), B(M);
  long long sum = (long long)N * (N - 1) / 2;
  UnionFind uf(N);
  vector<long long> ans(M);
  for (int m = 0; m < M; m++) {
    cin >> A.at(m) >> B.at(m);
    A.at(m)--;
    B.at(m)--;
  }
  for (int m = M - 1; m >= 0; m--) {
    ans.at(m) = sum;
    if (uf.issame(A.at(m), B.at(m))) {
      continue;
    }
    int a = uf.size(A.at(m));
    int b = uf.size(B.at(m));
    uf.unite(A.at(m), B.at(m));
    int c = a + b;
    long long delta = (long long)c * (c - 1) / 2 - (long long)a * (a - 1) / 2 - (long long)b * (b - 1) / 2;
    sum -= delta;
  }
  for (int m = 0; m < M; m++) {
    cout << ans.at(m) << endl;
  }
  return 0;
}
