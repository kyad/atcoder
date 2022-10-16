#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

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

mint comb2(mint M) {
  return M * (M - 1) / 2;
}

mint pow(int M, long long n) {
  mint x = M;
  return x.pow(n);
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
    P.at(n)--;
  }
  mint comb2M = comb2((mint)M);
  mint ans = 0;
  UnionFind uf(N);
  int n = N;
  for (int i = 0; i < N; i++) {
    if (uf.issame(i, P[i])) {
      continue;
    }
    mint now = comb2M * pow(M, n - 2);
    ans += now;
    uf.unite(i, P[i]);
    n--;
  }
  cout << ans.val() << endl;
  return 0;
}
