#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
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

// m^n, O(log n)
long long power(long long m, long long n, int mod) {
  long long a = m % mod;
  long long ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    n >>= 1;
  }
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<tuple<long long, int, int> > edges;  // weight, u, v
  for (int u = 0; u < N; u++) {
    for (int v = u + 1; v < N; v++) {
      long long x = A[u];
      long long y = A[v];
      long long a = power(x, y, M);
      long long b = power(y, x, M);
      long long now = a + b;
      now %= M;
      edges.push_back(make_tuple(now, u, v));
    }
  }
  sort(edges.begin(), edges.end());
  reverse(edges.begin(), edges.end());
  UnionFind uf(N);
  long long ans = 0;
  for (size_t i = 0; i < edges.size(); i++) {
    long long weight = get<0>(edges[i]);
    int u = get<1>(edges[i]);
    int v = get<2>(edges[i]);
    if (uf.issame(u, v)) {
      continue;
    }
    ans += weight;
    uf.unite(u, v);
  }
  cout << ans << endl;
  return 0;
}
