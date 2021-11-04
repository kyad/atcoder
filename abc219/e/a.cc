// https://atcoder.jp/contests/abc219/tasks/abc219_e

#include <iostream>
#include <vector>
using namespace std;

void draw_map(int bit) {
  cout << "bit=" << bit << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << ((bit >> (i * 4 + j))&1);
    }
    cout << endl;
  }
}

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
  vector<int> A(16);
  for (int i = 0; i < 16; i++) {
    cin >> A.at(i);
  }
  int ans = 0;
  for (int bit = 1; bit < (1<<16); bit++) {
    // Check if connected
    UnionFind uf(17);  // 16 == outside
    for (int u = 0; u < 16; u++) {
      int uy = u / 4;
      int ux = u % 4;
      const int dy[4] = {-1, 0, 1, 0};
      const int dx[4] = {0, -1, 0, 1};
      for (int k = 0; k < 4; k++) {
        int vy = uy + dy[k];
        int vx = ux + dx[k];
        if ((bit >> u) & 1) {
          if (vy < 0 || vy >= 4 || vx < 0 || vx >= 4) {
            continue;
          }
          int v = vy * 4 + vx;
          if ((bit >> v) & 1) {
            uf.unite(u, v);
          }
        } else {
          // Check if have hole
          if (vy < 0 || vy >= 4 || vx < 0 || vx >= 4) {
            uf.unite(u, 16);  // touch to outside
          } else {
            int v = vy * 4 + vx;
            if (!((bit >> v) & 1)) {
              uf.unite(u, v);
            }
          }
        }
      }
    }
    int area = 0;
    for (int u = 0; u < 16; u++) {
      if ((bit >> u) & 1) {
        area++;
      }
    }
    bool valid_moat = true;
    for (int u = 0; u < 16; u++) {
      if ((bit >> u) & 1) {
        if (uf.size(u) != area) {
          valid_moat = false;
        }
      } else {
        if (uf.size(u) != 16 + 1 - area) {  // + 1: outside(16)
          valid_moat = false;
        }
      }
    }
    if (!valid_moat) {
      continue;
    }
    bool village_in = true;
    for (int u = 0; u < 16; u++) {
      if (A[u]) {
        if (!((bit >> u) & 1)) {
          village_in = false;
        }
      }
    }
    if (village_in) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
