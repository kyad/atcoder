#include <cmath>
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

bool check_on(long long x0, long long y0, long long r0, long long x, long long y) {
  return (x - x0) * (x - x0) + (y - y0) * (y - y0) == r0 * r0;
}

bool check_cross(long long x0, long long y0, long long r0, long long x1, long long y1, long long r1) {
  bool b = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) <= (r1 + r0) * (r1 + r0);
  if (!b) {
    return false;
  }
  double d1 = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
  double rmin = min(r0, r1);
  double rmax = max(r0, r1);
  const double eps = 1e-12;
  return d1 + rmin - rmax >= -eps;
}



int main() {
  int N;
  cin >> N;
  long long SX, SY, TX, TY;
  cin >> SX >> SY >> TX >> TY;
  vector<long long> X(N), Y(N), R(N);
  for (int n = 0; n < N; n++) {
    cin >> X.at(n) >> Y.at(n) >> R.at(n);
  }
  int S = -1, T = -1;
  for (int n = 0; n < N; n++) {
    if (check_on(X[n], Y[n], R[n], SX, SY)) {
      S = n;
    }
    if (check_on(X[n], Y[n], R[n], TX, TY)) {
      T = n;
    }
  }
  UnionFind uf(N);
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (check_cross(X[i], Y[i], R[i], X[j], Y[j], R[j])) {
        uf.unite(i, j);
      }
    }
  }
  bool ans = uf.issame(S, T);
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
