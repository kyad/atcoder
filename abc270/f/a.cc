#include <algorithm>
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


int main() {
  int N, M;
  cin >> N >> M;
  vector<int> X(N), Y(N);
  for (int n = 0; n < N; n++) {
    cin >> X.at(n);
  }
  for (int n = 0; n < N; n++) {
    cin >> Y.at(n);
  }
  vector<tuple<int, int, int> > Z;  // cost, u, v
  for (int m = 0; m < M; m++) {
    int a, b, z;
    cin >> a >> b >> z;
    a--;
    b--;
    int u = min(a, b);
    int v = max(a, b);
    Z.push_back(make_tuple(z, u, v));
  }
  const long long INF = 4e18;
  long long ans = INF;
  for (int k = 0; k < 4; k++) {
    long long now = 0LL;
    vector<tuple<int, int, int> > edges(Z);  // cost, u, v
    int T = N;
    if (k % 2) {  // Use X
      for (int n = 0; n < N; n++) {
        edges.push_back(make_tuple(X[n], n, T));
      }
      T++;
    }
    if (k / 2) {  // Use Y
      for (int n = 0; n < N; n++) {
        edges.push_back(make_tuple(Y[n], n, T));
      }
      T++;
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(T);
    for (auto [cost, u, v] : edges) {
      if (uf.unite(u, v)) {
        now += cost;
      }
    }
    if (uf.size(0) < N) {
      now = INF;
    }
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
