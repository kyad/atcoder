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

const int MAX = 2001;
int encode(int x, int y) {
  x += 1000;
  y += 1000;
  return x * MAX + y;
}

pair<int, int> decode(int z) {
  int x = z / MAX;
  int y = z % MAX;
  x -= 1000;
  y -= 1000;
  return make_pair(x, y);
}

int main() {
  int N;
  cin >> N;
  int M = 2000 * MAX + 2000 + 1;
  vector<bool> black(M, false);
  for (int n = 0; n < N; n++) {
    int x, y;
    cin >> x >> y;
    black[encode(x, y)] = true;
  }
  UnionFind uf(M);
  for (int x = -1000; x <= 1000; x++) {
    for (int y = -1000; y <= 1000; y++) {
      int z = encode(x, y);
      if (!black[z]) {
        continue;
      }
      const int dx[6] = {-1, -1,  0, 0, 1, 1};
      const int dy[6] = {-1,  0, -1, 1, 0, 1};
      for (int k = 0; k < 6; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx <= -1001 || nx >= 1001 || ny <= -1001 || ny >= 1001) {
          continue;
        }
        int nz = encode(nx, ny);
        if (!black[nz]) {
          continue;
        }
        uf.unite(z, nz);
      }
    }
  }
  int ans = 0;
  for (int m = 0; m < M; m++) {
    if (black[m] && m == uf.root(m)) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
