#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct UnionFind {
  vector<int> parent, _size;
  int _num_unions;
  // UnonFindが範囲の時の左端と右端
  vector<int> _left;
  vector<int> _right;
  // 追加

  UnionFind(int n) : parent(n, -1), _size(n, 1), _num_unions(n) {
    _left.resize(n, 0);
    _right.resize(n, 0);
    for (int i = 0; i < n; i++) {
      _left.at(i) = i;
      _right.at(i) = i;
    }
    // 追加
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

    // 範囲の更新
    int nleft = min(_left.at(x), _left.at(y));
    _left.at(x) = nleft;
    int nright = max(_right.at(x), _right.at(y));
    _right.at(x) = nright;
    // 追加

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
};

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  int N = H * W;
  auto encode = [&](int y, int x) {
    return y * W + x;
  };
  UnionFind uf(N);
  const int dy[4] = {0, -1, 0, +1};
  const int dx[4] = {+1, 0, -1, 0};
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S.at(y).at(x) == '.') {
        int z = encode(y, x);
        for (int k = 0; k < 4; k++) {
          int ny = y + dy[k];
          int nx = x + dx[k];
          int nz = encode(ny, nx);
          if (ny >= 0 && ny < H && nx >= 0 && nx < W && S.at(ny).at(nx) == '.') {
            uf.unite(z, nz);
          }
        }
      }
    }
  }
  set<int> st;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S.at(y).at(x) == '.') {
        int z = encode(y, x);
        int root = uf.root(z);
        st.insert(root);
      }
    }
  }
  // 外周を除外
  for (int y = 0; y < H; y++) {
    if (S.at(y).at(0) == '.') {
      int z = encode(y, 0);
      int root = uf.root(z);
      st.erase(root);
    }
    if (S.at(y).at(W - 1) == '.') {
      int z = encode(y, W - 1);
      int root = uf.root(z);
      st.erase(root);
    }
  }
  for (int x = 0; x < W; x++) {
    if (S.at(0).at(x) == '.') {
      int z = encode(0, x);
      int root = uf.root(z);
      st.erase(root);
    }
    if (S.at(H - 1).at(x) == '.') {
      int z = encode(H - 1, x);
      int root = uf.root(z);
      st.erase(root);
    }
  }
  int ans = st.size();
  cout << ans << '\n';
  return 0;
}
