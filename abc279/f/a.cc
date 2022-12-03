// https://atcoder.jp/contests/abc279/tasks/abc279_f

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
  int N, Q;
  cin >> N >> Q;
  UnionFind uf(N + Q + 1);
  // ボールのroot→そのボールが入っている箱番号。-1の時、そのボールはrootでない。
  vector<int> idx(N + Q + 1, -1);
  // 箱番号→ボールのroot。-1の時、箱は空。
  vector<int> root(N + Q + 1, -1);
  for (int i = 1; i <= N + Q; i++) {
    idx[i] = i;
    root[i] = i;
  }
  int k = N;
  for (int q = 0; q < Q; q++) {
    int op, X;
    cin >> op >> X;
    if (op == 1 || op == 2) {
      int Y;
      if (op == 1) {
        cin >> Y;
      } else {
        Y = k + 1;
        k++;
      }
      int rx = root.at(X);
      int ry = root.at(Y);
      int nrx;
      if (ry < 0) {
        continue;
      } else if (rx < 0) {
        nrx = ry;
      } else  {
        uf.unite(rx, ry);
        nrx = uf.root(rx);
        idx.at(rx) = -1;
      }
      root.at(X) = nrx;
      idx.at(ry) = -1;
      idx.at(nrx) = X;
      root.at(Y) = -1;
    } else {
      int r = uf.root(X);
      int ans = idx.at(r);
      assert(ans >= 0);
      cout << ans << endl;
    }
  }
  return 0;
}
