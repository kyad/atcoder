#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<int> cnt;

struct UnionFind {
  vector<int> parent, _size;
  int _num_unions;
  // 追加
  vector<int> _color;
  vector<int> _left;
  vector<int> _right;

  UnionFind(int n) : parent(n, -1), _size(n, 1), _num_unions(n) {
    // 追加
    _color.resize(n, 0);
    for (int i = 0; i < n; i++) {
      _color.at(i) = i;
    }
    _left.resize(n, 0);
    _right.resize(n, 0);
    for (int i = 0; i < n; i++) {
      _left.at(i) = i;
      _right.at(i) = i;
    }
  }

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
    // xが新しい親
    parent[y] = x;
    _size[x] += _size[y];
    _num_unions--;

    // 追加
    int nleft = min(_left.at(x), _left.at(y));
    _left.at(x) = nleft;
    int nright = max(_right.at(x), _right.at(y));
    _right.at(x) = nright;

    return true;
  }

  int size(int x) {
    return _size[root(x)];
  }

  int num_unions() {  // unionの数(ひとまとまりになっているグループの数)を返す
    return _num_unions;
  }

  int left(int x) {
    return _left[root(x)];
  }

  int right(int x) {
    return _right[root(x)];
  }

  int get_color(int x) {
    return _color[root(x)];
  }

  void set_color(int x, int c) {
    _color[root(x)] = c;
  }
};

#if 0
void print_uf(UnionFind &uf) {
  int N = uf.parent.size();
  {
    vector<int> root;
    for (int x = 0; x < N; x++) {
      root.push_back(uf.root(x));
    }
    print(root);
  }
  {
    vector<int> left;
    for (int x = 0; x < N; x++) {
      left.push_back(uf.left(x));
    }
    print(left);
  }
  {
    vector<int> right;
    for (int x = 0; x < N; x++) {
      right.push_back(uf.right(x));
    }
    print(right);
  }
  {
    vector<int> color;
    for (int x = 0; x < N; x++) {
      color.push_back(uf.get_color(x));
    }
    print(color);
  }
}
#endif

int solve() {
  int N, Q;
  cin >> N >> Q;
  UnionFind uf(N);
  cnt.resize(N, 1);  // count[c]: 色cの個数
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, c;
      cin >> x >> c;
      x--; c--;
      int prevc = uf.get_color(x);
      uf.set_color(x, c);
      cnt.at(prevc) -= uf.size(x);
      cnt.at(c) += uf.size(x);
      int l = uf.left(x);
      if (l >= 1 && uf.get_color(l - 1) == c) {
        uf.unite(l - 1, x);
      }
      int r = uf.right(x);
      if (r <= N - 2 && uf.get_color(r + 1) == c) {
        uf.unite(r + 1, x);
      }
    } else {
      int c;
      cin >> c;
      c--;
      int ans = cnt.at(c);
      cout << ans << '\n';
    }
  }
  return 0;
}

int main() {
  solve();
  return 0;
}
