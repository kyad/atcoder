#include <algorithm>
#include <cassert>
#include <iostream>
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
  int N, M;
  long long K;
  cin >> N >> M >> K;
  vector<int> U(M), V(M);
  vector<long long> W(M);
  for (int m = 0; m < M; m++) {
    cin >> U.at(m) >> V.at(m) >> W.at(m);
    U.at(m)--; V.at(m)--;
  }

  // next_combination(M, r)
  const int r = N - 1;
  vector<int> mask(M, 1);
  for (int i = 0; i < M - r; i++) {
    mask.at(i) = 0;
  }
  const long long INF = 4e18;
  long long ans = INF;
  do {
    UnionFind uf(N);
    long long now = 0;
    for (int i = 0; i < M; i++) {
      if (mask.at(i)) {
        // Do something
        int u = U.at(i);
        int v = V.at(i);
        long long w = W.at(i);
        uf.unite(u, v);
        now += w;
        now %= K;
      }
    }
    if (uf.num_unions() == 1) {
      ans = min(ans, now);
    }
  } while (next_permutation(mask.begin(), mask.end()));
  cout << ans << endl;
  return 0;
}
