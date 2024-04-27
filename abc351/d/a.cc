#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
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
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }

  const int dy[4] = {1, 0, -1, 0};
  const int dx[4] = {0, 1, 0, -1};
  // xをつける
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S[y][x] == '#') {
        for (int k = 0; k < 4; k++) {
          int ny = y + dy[k];
          int nx = x + dx[k];
          if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
            continue;
          }
          if (S[ny][nx] == '.') {
            S[ny][nx] = 'x';
          }
        }
      }
    }
  }

  auto encode = [&](int y, int x) -> int {
    return y * W + x;
  };

  int N = W * H;
  UnionFind uf(N);

  // 1. 各.をつなげてrootを求める
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      int z = encode(y, x);
      if (S[y][x] != '.') {
        continue;
      }
      for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
          continue;
        }
        if (S[ny][nx] == '.') {
          int nz = encode(ny, nx);
          uf.unite(z, nz);
        }
      }
    }
  }

  // 2. 各.からrootの個数を求める
  vector<int> count(N, 0);
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S[y][x] == '.') {
        int z = encode(y, x);
        int root = uf.root(z);
        count[root]++;
      }
    }
  }

  // 3. 各xの4近傍の.からrootへの寄与を求める
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S[y][x] != 'x') {
        continue;
      }
      set<int> roots;
      for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
          continue;
        }
        if (S[ny][nx] == '.') {
          int nz = encode(ny, nx);
          int root = uf.root(nz);
          if (roots.contains(root)) {
            continue;
          }
          count[root]++;
          roots.insert(root);
        }
      }
    }
  }

  int ans = *max_element(count.begin(), count.end());
  ans = max(1, ans);

  cout << ans << endl;
  return 0;
}
