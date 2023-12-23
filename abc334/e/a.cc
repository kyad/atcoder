#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// modint
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}

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
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  int N = H * W;
  auto encode = [&](int y, int x) {
    int ans = y * W + x;
    return ans;
  };
  UnionFind uf(N);
  int dy[4] = {0, 1, 0, -1};
  int dx[4] = {1, 0, -1, 0};

  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S[y][x] == '.') {
        continue;
      }
      int z = encode(y, x);
      for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (nx < 0 || nx >= W || ny < 0 || ny >= H || S[ny][nx] == '.') {
          continue;
        }
        int nz = encode(ny, nx);
        if (S[y][x] == S[ny][nx]) {
          uf.unite(z, nz);
        }
      }
    }
  }
  set<int> st0;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S[y][x] == '#') {
        int z = encode(y, x);
        st0.insert(uf.root(z));
      }
    }
  }
  mint all = st0.size();
  mint E = 0;
  int count = 0;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S[y][x] == '#') {
        continue;
      }
      set<int> st;
      for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (nx < 0 || nx >= W || ny < 0 || ny >= H || S[ny][nx] == '.') {
          continue;
        }
        int nz = encode(ny, nx);
        st.insert(uf.root(nz));
      }
      int delta = st.size() - 1;
      assert(-1 <= delta && delta <= 3);
      mint now = all - delta;
      E += now;
      count++;
    }
  }
  mint ans = 0;
  if (count == 0) {
    ans = all;
  } else {
    ans = E / count;
  }
  cout << ans << endl;
  return 0;
}
